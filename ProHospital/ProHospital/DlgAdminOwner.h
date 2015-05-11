#pragma once
#include "CUser.h"

// CDlgAdminOwner dialog

class CDlgAdminOwner : public CDialog
{
	DECLARE_DYNAMIC(CDlgAdminOwner)

public:
	CDlgAdminOwner(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgAdminOwner();

// Dialog Data
	enum { IDD = IDD_DIALOG_ADMINOWEN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonCreateu();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
private:

	AdminUser* cuser_;

public:
	void SetAdUser(AdminUser* u)
	{
		cuser_ = u;
	}
};
