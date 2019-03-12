#ifndef _MOONTALK_SRC_UTILCOMMONAPI_H_
#define _MOONTALK_SRC_UTILCOMMONAPI_H_

#include <atlstr.h>
#include <string>

namespace util {

	void CreateUserDirectory(const char* username);

	char* GetUserDirPath();

	void SaveUserName(const std::string& userName);

	std::string GetLoginUserName();

	CString stringToCString(const std::string& src);
}


#endif // !_MOONTALK_SRC_UTILCOMMONAPI_H_