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
  * JsonBody.h
  *
  * This is a JSON http body which can be submitted via http
  */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_JsonBody_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_JsonBody_H_


#include "IHttpBody.h"

#include <cpprest/json.h>

namespace mvshyvk {
namespace kaldi {
namespace client {
namespace model {

class  JsonBody
	: public IHttpBody
{
public:
	JsonBody(const web::json::value& value);
	virtual ~JsonBody();

	void writeTo(std::ostream& target) override;

protected:
	web::json::value m_Json;
};

}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_JsonBody_H_ */
