#include "UtilCommonAPI.h"
#include <shlobj.h>
#include <shlwapi.h>
#include <string>

using namespace util;

static char DirPath[MAX_PATH] = {0};
static std::string g_UserName;
void util::CreateUserDirectory(const char* username)
{
	char my_documents[MAX_PATH] = { 0 };
	HRESULT result = SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, my_documents);
	CString str = CString(my_documents) + "\\MoonTalk";
	if (!PathIsDirectory(str))
	{
		CreateDirectory(str, NULL);
	}
	str +=  "\\";str += username;
	if (!PathIsDirectory(str))
	{
		CreateDirectory(str, NULL);
	}

	SetCurrentDirectory(str);  //改变工作目录到用户文件夹下
}

char* util::GetUserDirPath()
{

	return DirPath;
}


void util::SaveUserName(const std::string& userName)
{
	g_UserName = userName;
}

std::string util::GetLoginUserName()
{
	return g_UserName;
}


CString util::stringToCString(const std::string& src)
{
	CString dst;
	if (src.empty())
	{
		return  dst;
	}
	int length = ::MultiByteToWideChar(CP_UTF8, 0, src.data(), (int)src.size(), NULL, 0);
	WCHAR* pBuffer = dst.GetBufferSetLength(length);
	::MultiByteToWideChar(CP_UTF8, 0, src.data(), (int)src.size(), pBuffer, length);

	return dst;
}