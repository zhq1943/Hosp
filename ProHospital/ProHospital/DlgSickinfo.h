#pragma once
#include "CUser.h"
#include "afxwin.h"

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
public:
	CString m_name;
	CString m_timein;
	CString m_timeout;
	CString m_patkb;
	CString m_badid;
	CString m_hosid;
	CString m_pasid;
	CString m_ttalk;
	CString m_mtalk;
	CString m_nsick;
	CEdit m_incheck;
	CString m_outcheck;

	void SetInfo(CUser*);
	CString m_vincheck;
	afx_msg void OnBnClickedButtonModisickinfo();
	void SetModify_();

private:
	wstring user_name;
};
