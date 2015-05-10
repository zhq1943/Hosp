#pragma once


// CDlgAdminOwner dialog

class CDlgAdminOwner : public CDialog
{
	DECLARE_DYNAMIC(CDlgAdminOwner)

public:
	CDlgAdminOwner(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgAdminOwner();

// Dialog Data
	enum { IDD = IDD_DIALOG_ADMINOWEN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
