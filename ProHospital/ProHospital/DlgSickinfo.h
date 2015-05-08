#pragma once
#include "CUser.h"

// CDlgSickinfo dialog

class CDlgSickinfo : public CDialog
{
	DECLARE_DYNAMIC(CDlgSickinfo)

public:
	CDlgSickinfo(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgSickinfo();

// Dialog Data
	enum { IDD = IDD_DIALOG_SICKINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	CUser m_user;
};
