#ifdef _WIN32
#include <windows.h>
#endif
#include "StringTools.h"

namespace mvshyvk
{

// Conversion utility::string_t to std::string
std::string ToString(utility::string_t srcString)
{
#ifdef _WIN32
	// Allocating buffer
	auto size = WideCharToMultiByte(CP_ACP, NULL, srcString.c_str(), -1,
		nullptr, 0, nullptr, nullptr);
	auto convertedString = std::shared_ptr<char>(new char[size]);

	// Converting Unicode to ASCII
	WideCharToMultiByte(CP_ACP, NULL, srcString.c_str(), -1,
		convertedString.get(), size, nullptr, nullptr);

	return std::string(convertedString.get());
#else
	return srcString;
#endif
}

// Conversion std::string to utility::string_t
utility::string_t FromString(std::string srcString)
{
#ifdef _WIN32
	// Allocating buffer
	auto size = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, srcString.c_str(), -1,
		nullptr, 0);
	auto wideStr = std::shared_ptr<WCHAR>(new WCHAR[size]);

	// Converting to wide string
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, srcString.c_str(), -1,
		wideStr.get(), size);

	return utility::string_t(wideStr.get());
#else
	return srcString;
#endif
}

// Conversion UTF std::string to platform/console specific std::string (UTF8 for linux or ASCII for Windows)
std::string FromUtf8String(std::string srcString)
{
#ifdef _WIN32

	// UTF8 to wide char
	int size = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, srcString.c_str(), -1,
		nullptr, 0);
	auto wideStr = std::shared_ptr<WCHAR>(new WCHAR[size]);
	MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, srcString.c_str(), -1,
		wideStr.get(), size);

	// Wide char â ASCII
	BOOL bUsedDefaultCharacter = FALSE;
	size = WideCharToMultiByte(CP_ACP, 0, wideStr.get(), -1,
		nullptr, 0, "?", &bUsedDefaultCharacter);
	auto asciiStr = std::shared_ptr<char>(new char[size]);
	WideCharToMultiByte(CP_ACP, 0, wideStr.get(), -1,
		asciiStr.get(), size, "?", &bUsedDefaultCharacter);

	return std::string(asciiStr.get());
#else
	return srcString;
#endif
}
	
}
