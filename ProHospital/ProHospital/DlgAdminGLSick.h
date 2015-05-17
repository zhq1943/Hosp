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

	afx_msg void OnBnClickedButtonModify();
	afx_msg void OnBnClickedButtonCreate();
	afx_msg void OnBnClickedButtonPer();
	afx_msg void OnBnClickedButtonNext();
	void SetSickInfo(CUser* );
	AdminUser* aduser;
	CString m_uname_;
	CString m_urname;
	CComboBox m_combo_time;
	CString m_sickrecord;

	int ind;
	map<wstring, wstring> all_record;
	void GetRecordbyTime(wstring ti_);

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonDelrec();
	afx_msg void OnCbnSelchangeCombo1Timeglsick();
	void  RestData();
};
