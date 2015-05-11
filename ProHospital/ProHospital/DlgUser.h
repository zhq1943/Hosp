#pragma once
#include "CUser.h"
#include "NormalUser.h"
#include "DlgSickinfo.h"
#include "DlgAdminInfo.h"
#include "DlgAdminGLSick.h"
#include "DlgAdminGLUser.h"
#include "DlgAdminOwner.h"
#include "afxcmn.h"
// CDlgUser dialog

class CDlgUser : public CDialog
{
	DECLARE_DYNAMIC(CDlgUser)

public:
	CDlgUser(CUser user, CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgUser();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };
	virtual BOOL OnInitDialog();


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	CUser userlogin;
	NormalUser noruser;
	AdminUser aduser;
	CNormalUser dlg_info;
	CDlgSickinfo dlg_sickinfo;
	CDlgAdminInfo dlg_admininfo;
	CDlgAdminGLUser dlg_admingluser;
	CDlgAdminGLSick dlg_adminglsick;
	CDlgAdminOwner dlg_adminowner;
	vector<UserLoginfo> alluser;
	
public:
	CTabCtrl m_tabctrl;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
