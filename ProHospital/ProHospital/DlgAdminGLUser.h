#pragma once
#include "afxcmn.h"
#include "CUser.h"
#include "NormalUser.h"
#include "DlgChangeMIMA.h"
#include "afxwin.h"
// CDlgAdminGLUser dialog

class CDlgAdminGLUser : public CDialog
{
	DECLARE_DYNAMIC(CDlgAdminGLUser)

public:
	CDlgAdminGLUser(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgAdminGLUser();

// Dialog Data
	enum { IDD = IDD_DIALOG_ADMINGLUSER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_usergl;
	virtual BOOL OnInitDialog();
	void SetInfo(vector<UserLoginfo>& alluser);
	
	afx_msg void OnNMDblclkListUser(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickListUser(NMHDR *pNMHDR, LRESULT *pResult);
	CMenu cpop_menu;
	afx_msg void On32771();
	CString  sel_user;
	CNormalUser dlg_noruser;
	CDlgChangeMIMA dlg_mima;

	afx_msg void On32772();
	afx_msg void OnBnClickedOk();
	afx_msg void OnDelUser();
	void RestData();
	afx_msg void OnBnClickedButtonSearchuser();
	CComboBox m_cb_stype;
	CString m_ed_searstr;

	void SetAdmin_(AdminUser* ad)
	{
		admin_ = ad;
	}

private:
	vector<UserLoginfo> allinfo;
	AdminUser* admin_;
public:
	afx_msg void OnNMClickListUser(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
};
extern bool updatesick;
extern bool updateinfo;