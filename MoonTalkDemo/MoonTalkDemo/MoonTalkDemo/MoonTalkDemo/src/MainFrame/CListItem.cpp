#include "../Utility/UtilCommonAPI.h"
#include "CListItem.h"

CListItem::CListItem()
	: m_bActive(false)
{}

CListItem::~CListItem()
{
}

LPCTSTR CListItem::GetClass() const
{
	return _T("ListItemUI");
}
void CListItem::DoEvent(TEventUI& event)
{
	if (!m_bActive)
	{
		CTabLayoutUI* pTabUI = static_cast<CTabLayoutUI*>(this->FindSubControl(_T("tab")));
		if (event.Type == UIEVENT_MOUSELEAVE)
		{
			pTabUI->SelectItem(0);
		}
	}

	return __super::DoEvent(event);
}


void CListItem::SetActive(bool bActive)
{
	m_bActive = bActive;
	CTabLayoutUI* pTabUI = static_cast<CTabLayoutUI*>(this->FindSubControl(_T("tab")));
	if (m_bActive)
	{
		this->SetFixedHeight(64);
		pTabUI->SelectItem(1);
	}
	else
	{
		this->SetFixedHeight(48);
		pTabUI->SelectItem(0);
	}
	
}

void CListItem::SetName(const std::string& name)
{
	//_name = name;
	CTabLayoutUI* pTabUI = static_cast<CTabLayoutUI*>(this->FindSubControl(_T("tab")));
	int count = 2;
	for (int i = 0; i < count; ++i)
	{
		CContainerUI* pContainerUI = static_cast<CContainerUI*> (pTabUI->GetItemAt(i));
		CTextUI* pTextUI = static_cast<CTextUI*> (pContainerUI->FindSubControl(_T("username")));
		pTextUI->SetText(util::stringToCString(name));
	}
	
}

void CListItem::SetSign(const std::string& sign)
{
	
	CTabLayoutUI* pTabUI = static_cast<CTabLayoutUI*> (this->FindSubControl(_T("tab")));
	int count = pTabUI->GetCount();
	for (int i = 0; i < count; ++i)
	{
		CContainerUI* pContainerUI = static_cast<CContainerUI*> (pTabUI->GetItemAt(i));
		CTextUI* pTextUI = static_cast<CTextUI*> (pContainerUI->FindSubControl(_T("sign")));
		pTextUI->SetText(util::stringToCString(sign));
	}
	//_sign = util::stringToCString(sign);
}

void CListItem::SetSex(int sex)
{
	//_sex = sex;
	CTabLayoutUI* pTabUI = static_cast<CTabLayoutUI*> (this->FindSubControl(_T("tab")));
	int count = pTabUI->GetCount();
	for (int i = 0; i < count; ++i)
	{
		CContainerUI* pContainerUI = static_cast<CContainerUI*> (pTabUI->GetItemAt(i));
		CControlUI* pControUI = static_cast<CControlUI*> (pContainerUI->FindSubControl(_T("face")));
		if (sex)
		{
			pControUI->SetBkImage(_T("MainFrame/man.png"));
		}
		else
		{
			pControUI->SetBkImage(_T("MainFrame/woman.png"));
		}
		
	}
	
}
