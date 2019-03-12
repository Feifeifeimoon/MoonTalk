#include "SysFrame.h"

LPCTSTR SysFrame::GetWindowClassName() const
{
	return _T("Sys");
}

CDuiString SysFrame::GetSkinFile()
{
	return _T("Login\\Sys.xml");
}

CDuiString SysFrame::GetSkinFolder()
{
	return _T("");
}