#ifndef _MOONTALK_MAINFRAME_CLISTVIEW_H
#define _MOONTALK_MAINFRAME_CLISTVIEW_H

#define WIN32_LEAN_AND_MEAN
#include <UIlib.h>

using namespace DuiLib;


class CListViewUI : public CListUI, public IDialogBuilderCallback
{
public:
	CListViewUI();
	~CListViewUI();

	LPCTSTR GetClass() const;
	LPVOID GetInterface(LPCTSTR pstrName);
	//void DoEvent(TEventUI& event);
	int m_nActiveItem = -1;//标识选中的item
	bool SetActiveItem(int iIndex, bool bTakeFocus);
	CControlUI* CreateControl(LPCTSTR pstrClass);
};

#endif // !_MOONTALK_MAINFRAME_CLISTVIEW_H

