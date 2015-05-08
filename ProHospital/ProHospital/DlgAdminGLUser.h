#pragma once


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
};
