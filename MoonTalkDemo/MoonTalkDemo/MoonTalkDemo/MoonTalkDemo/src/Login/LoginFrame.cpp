#include "LoginFrame.h"
#include <string>
#include <sqlite3.h>
#include "../Client/ClientManage.h"
#include "../Client/TcpClient.h"
#include "../Protobuf/login.pb.h"
#include "../Message.h"
#include "../Utility/UtilCommonAPI.h"


LoginFrame* LoginFrame::_instance = nullptr;

DUI_BEGIN_MESSAGE_MAP(LoginFrame, WindowImplBase)
	DUI_ON_MSGTYPE(DUI_MSGTYPE_WINDOWINIT, OnInitialized)
	DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
	//DUI_ON_MSGTYPE(DUI_MSGTYPE_TEXTCHANGED, OnTextChanged)
	//DUI_ON_MSGTYPE(DUI_MSGTYPE_SETFOCUS, OnSetFocus)
DUI_END_MESSAGE_MAP()


std::string StringFromLPCTSTR(LPCTSTR str) {
#ifdef _UNICODE
	int size_str = WideCharToMultiByte(CP_UTF8, 0, str, -1, 0, 0, NULL, NULL);

	char* point_new_array = new char[size_str];

	WideCharToMultiByte(CP_UTF8, 0, str, -1, point_new_array, size_str, NULL, NULL);

	std::string return_string(point_new_array);
	delete[] point_new_array;
	point_new_array = NULL;
	return return_string;
#else
	return std::string(str);
#endif
}


LPCTSTR LoginFrame::GetWindowClassName() const
{
	return _T("LoginFrame");
}

inline CDuiString LoginFrame::GetSkinFile()
{ 
	return _T("Login\\Login.xml"); 
}

inline CDuiString LoginFrame::GetSkinFolder() 
{
	return _T("");
}

LRESULT LoginFrame::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (WM_NCLBUTTONDBLCLK == uMsg)//禁用双击标题栏最大化
	{
		return 0;
	}
	return WindowImplBase::HandleMessage(uMsg, wParam, lParam);
}


void LoginFrame::OnInitialized(TNotifyUI& msg)
{
	_BtLogin = static_cast<CButtonUI*> (m_PaintManager.FindControl(_T("loginbtn")));
	ASSERT(_BtLogin);
	_EdtUserName = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("name_edit")));
	ASSERT(_EdtUserName);
	_EdtPassWord = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("pwd_edit")));
	ASSERT(_EdtPassWord);
	_TextTips = static_cast<CTextUI*> (m_PaintManager.FindControl(_T("tips")));
	ASSERT(_TextTips);
	ClientManage::GetInstance()->init();
	ClientManage::GetInstance()->GetLoginClient()->setMessageCallback(
		std::bind(&LoginFrame::_messageCallback, this, std::placeholders::_1)
	);
}

void LoginFrame::OnClick(TNotifyUI& msg)
{
	if (msg.pSender == _BtLogin)
	{
		_Login();
	}
	__super::OnClick(msg);
}


void LoginFrame::_Login()
{
	CDuiString username = _EdtUserName->GetText().ToString();
	CDuiString password = _EdtPassWord->GetText();
	if (username.IsEmpty() || password.IsEmpty())
	{
		return;
	}
	User user;
	string user_name = StringFromLPCTSTR(username.GetData());
	string passwd = StringFromLPCTSTR(password.GetData());
	user.set_account(user_name);
	user.set_password(passwd);
	char buf[128] = {};
	user.SerializeToArray(buf, 128);
	int len = strlen(buf);
	LogIn login = {};
	login.length = len;
	login.type = MSG_TYPE_LOGIN;
	strncpy(login.buf, buf, len + 1);
	ClientManage::GetLoginClient()->send((char*)&login, sizeof(LogIn));
}

void LoginFrame::_messageCallback(char* buf)
{
	DataHeader dh = {};
	memcpy(&dh, buf, sizeof(dh));
	switch (dh.type)
	{
	case MSG_TYPE_LOGIN_RET:
	{
		LogInRet ret;
		memcpy(&ret, buf, sizeof(ret));
		if (ret.ret == 1) //登陆成功
		{
			CDuiString username = _EdtUserName->GetText().ToString();
			string user_name = StringFromLPCTSTR(username.GetData());
			util::SaveUserName(user_name);
			util::CreateUserDirectory(StringFromLPCTSTR(_EdtUserName->GetText().ToString().GetData()).c_str());
			ClientManage::GetLoginClient()->close();
			Close(IDYES);
		}
		else
		{
			_TextTips->SetText(_T("账号或密码错误"));
		}
	}
	default:
		break;
	}
}

void LoginFrame::OnTextChanged(TNotifyUI& msg)
{

}


bool LoginFrame::ShowLoginFrame()
{
	//_instance->Create(NULL, _T("LoginFrame"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	_instance->Create(NULL, _T("LoginFrame"), UI_CLASSSTYLE_DIALOG, WS_EX_STATICEDGE | WS_EX_APPWINDOW, 0, 0, 0, 0);
	_instance->CenterWindow();
	//ClientManage::GetInstance()->init();
	return (IDYES == _instance->ShowModal());
}

void LoginFrame::SetTipsText(LPCTSTR text)
{
	_TextTips->SetText(text);
}

LoginFrame* LoginFrame::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new LoginFrame();
	}
	return _instance;
}
