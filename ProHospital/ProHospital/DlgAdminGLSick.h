#pragma once


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
};
