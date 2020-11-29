#ifndef KaldiServiceApiH
#define KaldiServiceApiH

#include <string>

#include "apiClient/ApiClient.h"
#include "ServiceApi.h"
#include "TaskApi.h"

namespace mvshyvk
{
	
using namespace mvshyvk::kaldi::client::api;

/*
 * Class estanlishes connection to KaldiService API and provides
 * entry points for calling API endpoints
 */
class KaldiServiceApi
{
public:
	KaldiServiceApi(utility::string_t baseApiPath);
	auto InitializeApiClient() noexcept(false) -> void;

	auto GetTaskApi() const { return m_taskApi; }
	auto GetServiceApi() const { return m_serviceApi; }

private:
	utility::string_t m_baseApiPath;
	std::shared_ptr<ApiConfiguration> m_apiConfiguration;
	std::shared_ptr<ApiClient> m_apiClient;
	std::shared_ptr<TaskApi> m_taskApi;
	std::shared_ptr<ServiceApi> m_serviceApi;
};
	
}

#endif /* KaldiServiceApiH */