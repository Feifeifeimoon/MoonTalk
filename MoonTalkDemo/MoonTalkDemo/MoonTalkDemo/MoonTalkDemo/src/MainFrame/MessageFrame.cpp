
#include "MessageFrame.h"



DUI_BEGIN_MESSAGE_MAP(MessageFrame, WindowImplBase)
DUI_ON_MSGTYPE(DUI_MSGTYPE_WINDOWINIT, OnInitialized)
//DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
//DUI_ON_MSGTYPE(DUI_MSGTYPE_TEXTCHANGED, OnTextChanged)
//DUI_ON_MSGTYPE(DUI_MSGTYPE_SETFOCUS, OnSetFocus)
DUI_END_MESSAGE_MAP()


MessageFrame::MessageFrame()
{

}

LPCTSTR MessageFrame::GetWindowClassName() const
{
	return _T("MessageFrame");
}

CDuiString MessageFrame::GetSkinFile()
{
	return _T("MainFrame\\messageFrame.xml");
}

CDuiString MessageFrame::GetSkinFolder()
{
	return _T("");
}

LRESULT  MessageFrame::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	/*if (WM_NCLBUTTONDBLCLK == uMsg)//禁用双击标题栏最大化
	{
		return 0;
	}*/
	return WindowImplBase::HandleMessage(uMsg, wParam, lParam);
}

void MessageFrame::OnInitialized(TNotifyUI & msg)
{
}

void MessageFrame::Notify(TNotifyUI & msg)
{
	return __super::Notify(msg);
}

void MessageFrame::InitWindow()
{
}
