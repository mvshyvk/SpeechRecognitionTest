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

#include "JsonBody.h"

namespace mvshyvk {
namespace kaldi {
namespace client {
namespace model {

JsonBody::JsonBody(const web::json::value& json)
	: m_Json(json)
{
}

JsonBody::~JsonBody()
{
}

void JsonBody::writeTo(std::ostream& target)
{
	m_Json.serialize(target);
}

}
}
}
}
