#include "KaldiServiceApi.h"
#include "cpprest/details/basic_types.h"

utility::string_t apiRelativePath = _XPLATSTR("/KaldiService/rest");

namespace mvshyvk {

/*
 * Class constructor
 */
KaldiServiceApi::KaldiServiceApi(utility::string_t baseApiPath) :
	m_baseApiPath(baseApiPath)
{
}

/*
 * Initializes API Client and creates entry points for calling API services
 */
auto KaldiServiceApi::InitializeApiClient() noexcept(false) -> void
{
	// API path manipulations
	auto apiPathBuilder = web::uri_builder{};
	apiPathBuilder.set_path(m_baseApiPath);
	apiPathBuilder.append_path(apiRelativePath);

	// Setting up API configuration and ApiClient instance
	m_apiConfiguration = std::make_shared<ApiConfiguration>();
	m_apiConfiguration->setBaseUrl(apiPathBuilder.path());
	m_apiClient = std::make_shared<ApiClient>(m_apiConfiguration);

	// Creating API endpoint executors
	m_taskApi = std::make_shared<TaskApi>(m_apiClient);
	m_serviceApi = std::make_shared<ServiceApi>(m_apiClient);
}

}