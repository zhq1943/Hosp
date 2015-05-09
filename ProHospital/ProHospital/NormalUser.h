#pragma once
#include "CUser.h"

// CNormalUser dialog

class CNormalUser : public CDialog
{
	DECLARE_DYNAMIC(CNormalUser)

public:
	CNormalUser(/*CUser user, */CWnd* pParent = NULL);   // standard constructor
	virtual ~CNormalUser();

// Dialog Data
	enum { IDD = IDD_DIALOG_USERSET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CUser m_user;
	virtual BOOL OnInitDialog();
	CString m_name;
	CString m_username;
	CString m_sex;
	CString m_birthday;
	CString m_hometown;
	CString m_warkplace;
	CString m_liveplace;
	CString m_ifmarry;
	void SetInfo(NormalUser&);
};
