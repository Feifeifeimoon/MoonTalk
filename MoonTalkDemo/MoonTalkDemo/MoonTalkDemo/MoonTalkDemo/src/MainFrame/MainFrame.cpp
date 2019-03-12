#include <atlstr.h>		//CString
#include "MainFrame.h"
#include "../Client/ClientManage.h"
#include "../Client/TcpClient.h"
#include "../Utility/UtilCommonAPI.h"
#include "CListView.h"
#include "CListItem.h"
#include "MessageFrame.h"
#include "../Protobuf/userInfo.pb.h"
#include "../Message.h"
#include <sqlite3.h>

MainFrame* MainFrame::_instance = nullptr;

DUI_BEGIN_MESSAGE_MAP(MainFrame, WindowImplBase)
	DUI_ON_MSGTYPE(DUI_MSGTYPE_WINDOWINIT, OnInitialized)
	//DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
	//DUI_ON_MSGTYPE(DUI_MSGTYPE_TEXTCHANGED, OnTextChanged)
	//DUI_ON_MSGTYPE(DUI_MSGTYPE_SETFOCUS, OnSetFocus)
DUI_END_MESSAGE_MAP()



MainFrame::MainFrame()
	: _myInfo(new UserInfo())
{

}

LPCTSTR MainFrame::GetWindowClassName() const 
{ 
	return _T("MainFrame"); 
}

CDuiString MainFrame::GetSkinFile() 
{ 
	return _T("MainFrame\\Main.xml"); 
}

CDuiString MainFrame::GetSkinFolder() 
{ 
	return _T(""); 
}

LRESULT  MainFrame::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	/*if (WM_NCLBUTTONDBLCLK == uMsg)//禁用双击标题栏最大化
	{
		return 0;
	}*/
	return WindowImplBase::HandleMessage(uMsg, wParam, lParam);
 }

void MainFrame::OnInitialized(TNotifyUI& msg)
{
	_btFace = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("facebtn")));
	ASSERT(_btFace);
	_textUserName = static_cast<CTextUI*>(m_PaintManager.FindControl(_T("username")));
	ASSERT(_textUserName);
	_editSign = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("sign_edit")));
	ASSERT(_editSign);
	_listLayout = static_cast<CListViewUI*>(m_PaintManager.FindControl(_T("ListLayout")));
	ASSERT(_listLayout);
	ClientManage::MsgClientConnect();
	ClientManage::GetMsgClient()->setMessageCallback(
		std::bind(&MainFrame::_messageCallback, this, std::placeholders::_1)
	);
	DoInit();
}

void MainFrame::Notify(TNotifyUI& msg)
{
	if (msg.sType == _T("selectchanged"))
	{
		CDuiString strName = msg.pSender->GetName();
		if (strName == _T("RecentlyListbtn"))
		{
			UserListGet request = {};
			int len = _myInfo->userid().size();
			request.length = len;
			strncpy(request.buf, _myInfo->userid().c_str(), len + 1);
			ClientManage::GetMsgClient()->send((char*)&request, sizeof(request));
		}
	}
	
	else if (msg.sType == DUI_MSGTYPE_ITEMSELECT)
	{
		
		int index = _listLayout->GetCurSel();
		_listLayout->SetActiveItem(index, true);
		
		//DUI_MSGTYPE_ITEM
	}
	else if (msg.sType == DUI_MSGTYPE_ITEMACTIVATE)
	{
		MessageFrame* f = new MessageFrame();
		f->Create(NULL, _T("MessageFrame"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
		f->CenterWindow();
		f->ShowModal();
	}
	
	return __super::Notify(msg);
}


void MainFrame::InitWindow()
{
	MONITORINFO oMonitor = {};
	oMonitor.cbSize = sizeof(oMonitor);
	::GetMonitorInfo(::MonitorFromWindow(*this, MONITOR_DEFAULTTOPRIMARY), &oMonitor);
	CDuiRect rcWork = oMonitor.rcWork;

	CDuiRect rcWnd;
	GetWindowRect(m_hWnd, &rcWnd);
	int nWidth = rcWnd.GetWidth();
	int nHeight = rcWnd.GetHeight();

#ifdef _DEBUG
	SetWindowPos(m_hWnd, 0, rcWork.GetWidth() - nWidth - 100, 100, 280, rcWork.GetHeight() - 800, SWP_SHOWWINDOW);
#else
	SetWindowPos(m_hWnd, HWND_TOPMOST, rcWork.GetWidth() - nWidth - 100, 100, 280, rcWork.GetHeight() - 200, SWP_SHOWWINDOW);
#endif
}

void MainFrame::DoInit()
{
	sqlite3* DB = NULL;
	sqlite3_open("test.db",&DB);

	UserInfoGet userInfo = {};
	std::string userName = util::GetLoginUserName();
	userInfo.length = userName.size();
	strncpy(userInfo.username, userName.c_str(), userName.size() + 1);
	ClientManage::GetMsgClient()->send((char*)&userInfo, sizeof(userInfo));
}



/*非线程安全*/
MainFrame* MainFrame::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new MainFrame();
	}
	return _instance;
}

CString stringToCString(const std::string& src)
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

void MainFrame::_RefreshList(UserList& list)
{
	
	CListItem* pElement = NULL;
	UserInfo tmpUser;
	int size = list.userinfo_size();
	for (int i = 0; i < list.userinfo_size(); ++i)
	{
		tmpUser = list.userinfo(i);
		auto iter = _userMap.find(tmpUser.userid());
		if (iter != _userMap.end())
			continue;
		_userMap[tmpUser.userid()] = &tmpUser;
		if (!_builider.GetMarkup()->IsValid())
		{
			pElement = static_cast<CListItem*>(_builider.Create(_T("MainFrame\\recentlyListItem.xml"), (UINT)0, NULL, &m_PaintManager));
		}
		else
		{
			pElement = static_cast<CListItem*>(_builider.Create(this, &m_PaintManager));
		}
		pElement->SetMinHeight(48);
		_listLayout->Add(pElement);
		pElement->id = atoi(tmpUser.userid().c_str());
		pElement->SetName(tmpUser.nickname());
		pElement->SetSign(tmpUser.sign());
		pElement->SetSex(tmpUser.sex());
	}
}


void MainFrame::_messageCallback(char* buf)
{
	DataHeader dh = {};
	memcpy(&dh, buf, sizeof(dh));
	switch (dh.type)
	{
	case MSG_TYPE_GETUSERINFO_RET:
	{
		UserInfoRet ret = {};
		memcpy(&ret, buf, sizeof(UserInfoRet));
		_myInfo->ParseFromArray(ret.buf, ret.length);
		_textUserName->SetText(stringToCString(_myInfo->nickname()));
		_editSign->SetText(stringToCString(_myInfo->sign()));
		if (_myInfo->sex())
			_btFace->SetBkImage(_T("MainFrame/man_m.png"));
		else
			_btFace->SetBkImage(_T("MainFrame/woman_m.png"));
	}
	break;
	case MSG_TYPE_GETUSERLIST_RET:
	{
		UserListRet ret = {};
		UserList list;
		memcpy(&ret, buf, sizeof(UserListRet));
		list.ParseFromArray(ret.buf, ret.length);
		_RefreshList(list);
	}
	default:
		break;
	}
}