#include <iostream>
#include <thread>
#include <locale>
#ifdef _WIN32
#include <windows.h>
#endif

#include "apiClient/ApiClient.h"
#include "KaldiServiceApi.h"
#include "ServiceApi.h"
#include "StringTools.h"
#include "TaskApi.h"

using namespace mvshyvk::kaldi::client::api;
using namespace mvshyvk;


void InitializeAndGetServiceStatus(std::shared_ptr<KaldiServiceApi> api)
{
	api->InitializeApiClient();

	// Retrieving API state
	auto statusTask = api->GetServiceApi()->serviceStatusGet();
	auto status = statusTask.get();

	// Printing statistics
	std::cout << "KaldiService capabilities:" << std::endl;
	std::cout << "Workers count: " << status->getWorkersCount() << std::endl;
	std::cout << "Queue depth: " << status->getQueueDepth() << std::endl;
	std::cout << "Available slots: " << status->getAvailableQueueSlots() << std::endl << std::endl;
}

auto PostKaldiServiceTask(const char* fileName, std::shared_ptr<KaldiServiceApi> api) -> utility::string_t
{
	// Opening file
	auto inWave = std::make_shared<std::ifstream>();
	inWave->open(fileName, std::ios_base::in | std::ios_base::binary);
	if (!inWave->is_open())
	{
		std::cout << "Unable to read specified file  " << fileName << std::endl;
		inWave->exceptions(std::ios_base::badbit | std::ios_base::failbit);
	}

	auto httpContent = std::make_shared<HttpContent>();
	httpContent->setData(inWave);
	auto content = boost::optional<std::shared_ptr<HttpContent>>(httpContent);

	// Calling KaldiService API POST /task endpoint with file content
	std::cout << "Reading content of the file " << fileName << " and sending it to KaldiService ..." << std::endl;
	auto taskTask = api->GetTaskApi()->taskPost(content);

	// Waiting for taskId
	auto taskId = taskTask.get()->getTaskId();

	inWave->close();
	return taskId;
}

auto WaitTaskCompletion(std::shared_ptr<KaldiServiceApi> api, utility::string_t taskId) -> std::shared_ptr<Result>
{
	std::cout << "Waiting for task completion: .";
	std::cout.flush();
	std::shared_ptr<Result> result;
	web::http::status_code httpCode;

	do
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << ".";
		std::cout.flush();
		std::tie(result, httpCode) = api->GetTaskApi()->taskTaskIdStatusGet(taskId).get();
	} while (httpCode == web::http::status_code(204));

	return result;
}

/*
 * Main function of console tool for speach recognition that uses KaldiService API
 *
 * Usage: speachRecognitionTest <KaldiService API root> <audio file>
 * Usage example: speachRecognitionTest http://localhost:8080 example.mp3
 */
int main(int argc, char** argv)
{
#ifdef _WIN32
	// Setting russian 1251 code page
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#endif 

	// Checking required parameters
	if (argc < 3)
	{
		std::cout << "Usage: speachRecognitionTest <KaldiService API Path> <audio file>" << std::endl;
		return -1;
	}

	auto api = std::make_shared<KaldiServiceApi>(FromString(argv[1]));

	try
	{
		std::cout << "Connecting to KaldiService API using path " << argv[1] << std::endl << std::endl;
		InitializeAndGetServiceStatus(api);

		auto taskId = PostKaldiServiceTask(argv[2], api);
		std::cout << "TaskId: " << ToString(taskId) << std::endl;

		auto recognizedText = WaitTaskCompletion(api, taskId);
		std::cout << std::endl << "Recognized text: " << std::endl << ToString(recognizedText->getText()) << std::endl;
		return 0;
	}
	catch (ApiException& e)
	{
		std::cout << "ApiException: " << FromUtf8String(e.what()) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "exception: " << FromUtf8String(e.what()) << std::endl;
	}
	return -1;
}