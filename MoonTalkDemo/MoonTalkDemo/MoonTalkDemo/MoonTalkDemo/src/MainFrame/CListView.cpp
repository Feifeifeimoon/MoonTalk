#include "CListView.h"
#include "CListItem.h"
#include "MessageFrame.h"
#include "../Message.h"
CListViewUI::CListViewUI()
{
	//m_nActiveItem = -1;
	DUI__Trace(L"\t------CListViewUI");
}


CListViewUI::~CListViewUI()
{
}


LPCTSTR CListViewUI::GetClass() const
{
	return _T("CustomListViewUI");
}

LPVOID CListViewUI::GetInterface(LPCTSTR pstrName)
{
	if (_tcsicmp(pstrName, _T("ListView")) == 0)
		return this;
	return CListUI::GetInterface(pstrName);
}

CControlUI* CListViewUI::CreateControl(LPCTSTR pstrClass)
{
	if (_tcsicmp(pstrClass, L"ListItem") == 0)
		return new CListItem();
	return NULL;
}



bool CListViewUI::SetActiveItem(int iIndex, bool bTakeFocus)
{
	if (!__super::SelectItem(iIndex, bTakeFocus))
	{
		return false;
	}
	//取消原有的选中状态
	if (m_nActiveItem != -1)
	{
		CListItem* pItem = static_cast<CListItem*>(this->GetItemAt(m_nActiveItem));
		pItem->SetActive(false);
	}
	m_nActiveItem = iIndex;
	//将新的item选中状态
	if (m_nActiveItem != -1)
	{
		CListItem* pItem = static_cast<CListItem*>(this->GetItemAt(m_nActiveItem));
		pItem->SetActive(true);
	}
	return true;
}