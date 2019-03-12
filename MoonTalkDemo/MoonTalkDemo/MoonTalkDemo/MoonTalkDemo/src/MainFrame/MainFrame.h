#ifndef MOONTALK_MAIN_FRAME_H
#define MOONTALK_MAIN_FRAME_H
#define WIN32_LEAN_AND_MEAN
#include <UIlib.h>
#include <map>
using namespace DuiLib;

class CListViewUI;
class UserInfo;
class UserList;
class MainFrame : public WindowImplBase
{
public:
	DUI_DECLARE_MESSAGE_MAP()
public:
	virtual ~MainFrame() {};

	static MainFrame*  GetInstance();
	virtual LPCTSTR    GetWindowClassName() const;
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();
	virtual LRESULT    HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	void OnInitialized(TNotifyUI& msg);
	virtual void Notify(TNotifyUI& msg);
	virtual void InitWindow();
	void  DoInit();
private:
	MainFrame();
	MainFrame(const MainFrame&) {};
	void _RefreshList(UserList& list);
	void _messageCallback(char* buf);

private:
	
	static MainFrame* _instance;
	UserInfo*		  _myInfo;
	CDialogBuilder    _builider;
	CButtonUI*        _btFace;
	CEditUI*          _editSign;
	CTextUI*	      _textUserName;
	CListViewUI*      _listLayout;
	std::map<std::string, UserInfo*> _userMap;
};

#endif // !_MAIN_FRAME_H

