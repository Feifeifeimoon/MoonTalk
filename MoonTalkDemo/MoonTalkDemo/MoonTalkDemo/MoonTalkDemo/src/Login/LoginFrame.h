#ifndef MOONTALK_LOGIN_FRAME_H_
#define MOONTALK_LOGIN_FRAME_H_
#define WIN32_LEAN_AND_MEAN
#include <atlstr.h>
#include <UIlib.h>

using namespace DuiLib;

class LoginFrame : public WindowImplBase
{
public:
	static LoginFrame* GetInstance();				//单例模式
	virtual ~LoginFrame() {};						//析构函数

	DUI_DECLARE_MESSAGE_MAP()
public:
	virtual LPCTSTR    GetWindowClassName() const;
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();
	virtual LRESULT    HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	void			   OnInitialized(TNotifyUI& msg);
	void			   OnClick(TNotifyUI& msg);
	void			   OnTextChanged(TNotifyUI& msg);
	bool	           ShowLoginFrame();
	void			   SetTipsText(LPCTSTR text);
private:
	LoginFrame() {};
	LoginFrame(const LoginFrame&) {};
	void _Login();
	void _messageCallback(char* buf);

private:
	static LoginFrame* _instance;
	CButtonUI*		   _BtLogin = nullptr;
	CEditUI*		   _EdtUserName = nullptr;
	CEditUI*		   _EdtPassWord = nullptr;
	CTextUI*		   _TextTips = nullptr;
};

#endif // !


