#ifndef StringToolsH
#define StringToolsH

#include <string>
#include <cpprest/asyncrt_utils.h>

namespace mvshyvk {

// Conversion utility::string_t to std::string
std::string ToString(utility::string_t srcString);

// Conversion std::string to utility::string_t
utility::string_t FromString(std::string srcString);

// Conversion UTF std::string to platform/console specific std::string (UTF8 for linux or ASCII for Windows)
std::string FromUtf8String(std::string srcString);

};

#endif /* StringToolsH */