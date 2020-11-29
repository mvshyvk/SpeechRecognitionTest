#ifndef OctetStreamDataH
#define OctetStreamDataH

#include <memory>

#include "IHttpBody.h"
#include "HttpContent.h"
#include "ModelBase.h"


namespace mvshyvk {
namespace kaldi {
namespace client {
namespace model {

/*
 * OctetStreamData.h
 *
 * This class represents a container for building application/octet-stream requests.
 */
class  OctetStreamData : public IHttpBody
{
public:
	OctetStreamData(std::shared_ptr<HttpContent> binaryContent);
	virtual ~OctetStreamData() = default;

	void writeTo(std::ostream& target) override;

protected:
	std::shared_ptr<HttpContent> m_binaryContent;
};

}
}
}
}

#endif /* OctetStreamDataH */