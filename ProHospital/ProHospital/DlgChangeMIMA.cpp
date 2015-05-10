// DlgChangeMIMA.cpp : implementation file
//

#include "stdafx.h"
#include "ProHospital.h"
#include "DlgChangeMIMA.h"
#include "afxdialogex.h"
#include "CUser.h"

// CDlgChangeMIMA dialog

IMPLEMENT_DYNAMIC(CDlgChangeMIMA, CDialog)

CDlgChangeMIMA::CDlgChangeMIMA(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgChangeMIMA::IDD, pParent)
	, m_mima1(_T(""))
	, m_mima2(_T(""))
	, m_username(_T(""))
{

}

CDlgChangeMIMA::~CDlgChangeMIMA()
{
}

void CDlgChangeMIMA::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_MIMA1, m_mima1);
	DDX_Text(pDX, IDC_EDIT_MIMA2, m_mima2);
	DDX_Text(pDX, IDC_EDIT2, m_username);
}


BEGIN_MESSAGE_MAP(CDlgChangeMIMA, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgChangeMIMA::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgChangeMIMA::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDlgChangeMIMA message handlers


void CDlgChangeMIMA::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialog::OnOK();
	UpdateData();
	m_lginfo.password = m_mima1;
	AdminUser aduser;
	aduser.UpdateNorLogin(m_lginfo);
}


void CDlgChangeMIMA::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void CDlgChangeMIMA::SetUserLgInfo( UserLoginfo& u )
{
	m_lginfo = u;
}

BOOL CDlgChangeMIMA::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_username = m_lginfo.uname.c_str();
	UpdateData(FALSE);

	
	return TRUE;
}

void CDlgChangeMIMA::AddNewUser()
{
	GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
}

void CDlgChangeMIMA::ModifyMima()
{
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
}
