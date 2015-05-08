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
};
