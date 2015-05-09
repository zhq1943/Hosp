#pragma once
#include "afxwin.h"
#include "CUser.h"

// CDlgAdminGLSick dialog

class CDlgAdminGLSick : public CDialog
{
	DECLARE_DYNAMIC(CDlgAdminGLSick)

public:
	CDlgAdminGLSick(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgAdminGLSick();

// Dialog Data
	enum { IDD = IDD_DIALOG_ADMINGLSICK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_username;
	CString m_name;
	CComboBox m_time;
	afx_msg void OnBnClickedButtonModify();
	afx_msg void OnBnClickedButtonCreate();
	afx_msg void OnBnClickedButtonPer();
	afx_msg void OnBnClickedButtonNext();
	void SetSickInfo(CUser* );
	CString m_sickrec;
};
