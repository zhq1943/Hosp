// DlgAdminOwner.cpp : implementation file
//

#include "stdafx.h"
#include "ProHospital.h"
#include "DlgAdminOwner.h"
#include "afxdialogex.h"
#include "DlgChangeMIMA.h"

// CDlgAdminOwner dialog

IMPLEMENT_DYNAMIC(CDlgAdminOwner, CDialog)

CDlgAdminOwner::CDlgAdminOwner(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAdminOwner::IDD, pParent)
{

}

CDlgAdminOwner::~CDlgAdminOwner()
{
}

void CDlgAdminOwner::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgAdminOwner, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgAdminOwner::OnBnClickedOk)
	ON_BN_CLICKED(IDD_BUTTON_CREATEU, &CDlgAdminOwner::OnBnClickedButtonCreateu)
	ON_BN_CLICKED(IDCANCEL, &CDlgAdminOwner::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDlgAdminOwner message handlers


void CDlgAdminOwner::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialog::OnOK(); change admin mima
	if (cuser_)
	{
		UserLoginfo info;
		cuser_->GetSelfLoginInfo(info);
		CDlgChangeMIMA dlg;
		dlg.SetUserLgInfo(info);
		dlg.DoModal();

	}

}


void CDlgAdminOwner::OnBnClickedButtonCreateu()
{
	// TODO: Add your control notification handler code here
	//create user
	CDlgChangeMIMA dlg;
	dlg.AddNewUser();
	dlg.DoModal();

}


void CDlgAdminOwner::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	//CDialog::OnCancel(); info
}

BOOL CDlgAdminOwner::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;
}
