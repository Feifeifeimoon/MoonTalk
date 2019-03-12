#ifndef _MOONTALK_MAINFRAME_CLISTITEM_H
#define _MOONTALK_MAINFRAME_CLISTITEM_H

#include <UIlib.h>
#include <string>
using namespace DuiLib;

class CListItem : public CListContainerElementUI
{
public:
	CListItem();
	~CListItem();

	LPCTSTR GetClass() const;
	void DoEvent(TEventUI& event);

	bool m_bActive;
	void SetActive(bool bActive = true);
	void SetName(const std::string& name);
	void SetSign(const std::string& sign);
	void SetSex(int sex);
	int id;
private:
	

};


#endif // !_MOONTALK_MAINFRAME_CLISTITEM_H

