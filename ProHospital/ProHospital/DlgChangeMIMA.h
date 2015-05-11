#pragma once
#include "CUser.h"

// CDlgChangeMIMA dialog

class CDlgChangeMIMA : public CDialog
{
	DECLARE_DYNAMIC(CDlgChangeMIMA)

public:
	CDlgChangeMIMA(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChangeMIMA();

// Dialog Data
	enum { IDD = IDD_DIALOG_MODIMIMA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CString m_mima1;
	CString m_mima2;
	CString uname;
	void SetUName(CString name_)
	{
		uname = name_;
	}

	UserLoginfo m_lginfo;
	void SetUserLgInfo(UserLoginfo& u);
	CString m_username;

	virtual BOOL OnInitDialog();

	void AddNewUser();
	void ModifyMima();

	BOOL editsty;
	
};
