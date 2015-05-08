#pragma once


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
};
