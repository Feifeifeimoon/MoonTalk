#ifndef MOONTALK_MESSAGE_FRAME_H
#define MOONTALK_MESSAGE_FRAME_H
#define WIN32_LEAN_AND_MEAN
#include <UIlib.h>
#include <map>
using namespace DuiLib;

class CListViewUI;
class UserInfo;
class UserList;
class MessageFrame : public WindowImplBase
{
public:
	DUI_DECLARE_MESSAGE_MAP()
public:
	MessageFrame();
	virtual ~MessageFrame() {};

	//static MessageFrame*  GetInstance();
	virtual LPCTSTR    GetWindowClassName() const;
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();
	virtual LRESULT    HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	void OnInitialized(TNotifyUI& msg);
	virtual void Notify(TNotifyUI& msg);
	virtual void InitWindow();
private:
	
	MessageFrame(const MessageFrame&) {};
//	void _RefreshList(UserList& list);
	//void _messageCallback(char* buf);

private:
};

#endif // !_MAIN_FRAME_H

