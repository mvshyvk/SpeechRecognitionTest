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



#include "TaskId.h"

namespace mvshyvk {
namespace kaldi {
namespace client {
namespace model {




TaskId::TaskId()
{
	m_taskId = utility::conversions::to_string_t("");
	m_taskIdIsSet = false;
}

TaskId::~TaskId()
{
}

void TaskId::validate()
{
	// TODO: implement validation
}

web::json::value TaskId::toJson() const
{

	web::json::value val = web::json::value::object();

	if (m_taskIdIsSet)
	{
		val[utility::conversions::to_string_t("taskId")] = ModelBase::toJson(m_taskId);
	}

	return val;
}

bool TaskId::fromJson(const web::json::value& val)
{
	bool ok = true;

	if (val.has_field(utility::conversions::to_string_t("taskId")))
	{
		const web::json::value& fieldValue = val.at(utility::conversions::to_string_t("taskId"));
		if (!fieldValue.is_null())
		{
			utility::string_t refVal_taskId;
			ok &= ModelBase::fromJson(fieldValue, refVal_taskId);
			setTaskId(refVal_taskId);
		}
	}
	return ok;
}

void TaskId::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
	utility::string_t namePrefix = prefix;
	if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
	{
		namePrefix += utility::conversions::to_string_t(".");
	}
	if (m_taskIdIsSet)
	{
		multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("taskId"), m_taskId));
	}
}

bool TaskId::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
	bool ok = true;
	utility::string_t namePrefix = prefix;
	if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
	{
		namePrefix += utility::conversions::to_string_t(".");
	}

	if (multipart->hasContent(utility::conversions::to_string_t("taskId")))
	{
		utility::string_t refVal_taskId;
		ok &= ModelBase::fromHttpContent(multipart->getContent(utility::conversions::to_string_t("taskId")), refVal_taskId);
		setTaskId(refVal_taskId);
	}
	return ok;
}

utility::string_t TaskId::getTaskId() const
{
	return m_taskId;
}

void TaskId::setTaskId(const utility::string_t& value)
{
	m_taskId = value;
	m_taskIdIsSet = true;
}

bool TaskId::taskIdIsSet() const
{
	return m_taskIdIsSet;
}

void TaskId::unsettaskId()
{
	m_taskIdIsSet = false;
}
}
}
}
}

