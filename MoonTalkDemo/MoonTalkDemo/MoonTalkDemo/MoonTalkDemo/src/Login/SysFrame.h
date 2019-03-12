#ifndef MOONTALK_SYS_FRAME_H_
#define MOONTALK_SYX_FRAME_H_

#include <UIlib.h>

using namespace DuiLib;

class SysFrame : public WindowImplBase
{

	//DUI_DECLARE_MESSAGE_MAP()
public :
	virtual LPCTSTR    GetWindowClassName() const;
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetSkinFolder();
};

#endif
