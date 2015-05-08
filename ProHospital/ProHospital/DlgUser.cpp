// DlgUser.cpp : implementation file
//

#include "stdafx.h"
#include "ProHospital.h"
#include "DlgUser.h"
#include "afxdialogex.h"


// CDlgUser dialog

IMPLEMENT_DYNAMIC(CDlgUser, CDialog)

CDlgUser::CDlgUser(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgUser::IDD, pParent)
{

}

CDlgUser::~CDlgUser()
{
}

void CDlgUser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgUser, CDialog)
END_MESSAGE_MAP()

BOOL CDlgUser::OnInitDialog()
{
	CDialog::OnInitDialog();

	CString out_str;
	CString name_ = _T("");
	return TRUE;
}


// CDlgUser message handlers
