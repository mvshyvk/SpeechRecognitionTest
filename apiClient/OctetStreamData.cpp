#include "OctetStreamData.h"

using namespace mvshyvk::kaldi::client::model;


OctetStreamData::OctetStreamData(std::shared_ptr<HttpContent> binaryContent) :
	m_binaryContent(binaryContent)
{
}

void OctetStreamData::writeTo(std::ostream& target)
{
	// Writing binary stream 
	std::shared_ptr<std::istream> data = m_binaryContent->getData();

	data->seekg(0, data->end);
	std::vector<char> dataBytes(data->tellg());

	data->seekg(0, data->beg);
	data->read(&dataBytes[0], dataBytes.size());

	std::copy(dataBytes.begin(), dataBytes.end(), std::ostreambuf_iterator<char>(target));
}
