#pragma once


// CDlgUser dialog

class CDlgUser : public CDialog
{
	DECLARE_DYNAMIC(CDlgUser)

public:
	CDlgUser(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgUser();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };
	virtual BOOL OnInitDialog();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
