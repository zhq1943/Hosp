#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "CUser.h"

// CDlgAdminInfo dialog

class CDlgAdminInfo : public CDialog
{
	DECLARE_DYNAMIC(CDlgAdminInfo)

public:
	CDlgAdminInfo(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgAdminInfo();

// Dialog Data
	enum { IDD = IDD_DIALOG_ADMININFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_cb_stype;
	CString m_ed_sstr;
	CListCtrl m_lc_list;
	afx_msg void OnBnClickedButtonSear();
    CString sel_username;
	virtual BOOL OnInitDialog();
	AdminUser* admin_;

	void SetAdmin_(AdminUser* ad)
	{
		admin_ = ad;
	}

private:
	vector<UserLoginfo> allinfo;
	CString sel_user;
public:
	afx_msg void OnBnClickedButtonDcdata();
	afx_msg void OnNMClickListSearres(NMHDR *pNMHDR, LRESULT *pResult);
	void RestData();
};

// extern bool updatesick;
// extern bool updateinfo;
