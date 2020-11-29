/**
 * Kaldi speech recognition REST API
 * Simple REST interface for posting tasks for non realtime speech recognition
 *
 * The version of the OpenAPI document: 0.9.0
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 5.0.0-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

 /*
  * ServiceApi.h
  *
  *
  */

#ifndef ORG_OPENAPITOOLS_CLIENT_API_ServiceApi_H_
#define ORG_OPENAPITOOLS_CLIENT_API_ServiceApi_H_


#include "apiClient/ApiClient.h"

#include "ServiceStatus.h"


#include <boost/optional.hpp>

namespace mvshyvk {
namespace kaldi {
namespace client {
namespace api {

using namespace mvshyvk::kaldi::client::model;



class  ServiceApi
{
public:

	explicit ServiceApi(std::shared_ptr<const ApiClient> apiClient);

	virtual ~ServiceApi();

	/// <summary>
	/// 
	/// </summary>
	/// <remarks>
	/// Returns status of Kaldi speach recognition service
	/// </remarks>
	pplx::task<std::shared_ptr<ServiceStatus>> serviceStatusGet(
	) const;

protected:
	std::shared_ptr<const ApiClient> m_ApiClient;
};

}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_API_ServiceApi_H_ */

