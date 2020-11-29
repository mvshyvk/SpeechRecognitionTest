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
  * Segment.h
  *
  *
  */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_Segment_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_Segment_H_


#include "apiClient/ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace mvshyvk {
namespace kaldi {
namespace client {
namespace model {


/// <summary>
/// 
/// </summary>
class  Segment
	: public ModelBase
{
public:
	Segment();
	virtual ~Segment();

	/////////////////////////////////////////////
	/// ModelBase overrides

	void validate() override;

	web::json::value toJson() const override;
	bool fromJson(const web::json::value& json) override;

	void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
	bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

	/////////////////////////////////////////////
	/// Segment members

	/// <summary>
	/// 
	/// </summary>
	int32_t getTimeStart() const;
	bool timeStartIsSet() const;
	void unsettimeStart();

	void setTimeStart(int32_t value);

	/// <summary>
	/// 
	/// </summary>
	int32_t getTimeEnd() const;
	bool timeEndIsSet() const;
	void unsettimeEnd();

	void setTimeEnd(int32_t value);

	/// <summary>
	/// 
	/// </summary>
	utility::string_t getSegmentText() const;
	bool segmentTextIsSet() const;
	void unsetsegmentText();

	void setSegmentText(const utility::string_t& value);


protected:
	int32_t m_timeStart;
	bool m_timeStartIsSet;
	int32_t m_timeEnd;
	bool m_timeEndIsSet;
	utility::string_t m_segmentText;
	bool m_segmentTextIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_Segment_H_ */
