//#include <WinSock2.h>
#define WIN32_LEAN_AND_MEAN
#include <atlstr.h>
#include <string>
#include <UIlib.h>
#include <sqlite3.h>
#include "src/Login/LoginFrame.h"
#include "src/Login/SysFrame.h"
#include "src/MainFrame/MainFrame.h"
#include "src/Client/ClientManage.h"
#include "src/Client/TcpClient.h"
#include "src/Protobuf/login.pb.h"

#pragma comment( lib, "shell32.lib")

using namespace DuiLib;

#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("..\\gui\\"));
	errno_t error;
	WSADATA dat;						//window下启动网络环境
	if ((error = WSAStartup(MAKEWORD(2, 2), &dat)) != 0)
	{
		exit(-1);
	}

	//ClientManage::GetInstance()->init();

	LoginFrame* loginFrame = LoginFrame::GetInstance();
	//ClientManage::GetInstance()->init();
	if (! loginFrame->ShowLoginFrame())
	{
		ClientManage::GetLoginClient()->close();
		return 0;
	}
	/*sqlite3* Db2 = NULL;
	sqlite3_open("111.db",&Db2);*/
	MainFrame* MainFrame = MainFrame::GetInstance();
	MainFrame->Create(NULL, _T("MainFrame"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	MainFrame->CenterWindow();
	MainFrame->ShowModal();

	CPaintManagerUI::MessageLoop();
	CPaintManagerUI::Term();
	return 0;
}
