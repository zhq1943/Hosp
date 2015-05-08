// NormalUser.cpp : implementation file
//

#include "stdafx.h"
#include "ProHospital.h"
#include "NormalUser.h"
#include "afxdialogex.h"


// CNormalUser dialog

IMPLEMENT_DYNAMIC(CNormalUser, CDialog)

CNormalUser::CNormalUser(CWnd* pParent /*=NULL*/)
	: CDialog(CNormalUser::IDD, pParent)
{
	
}

CNormalUser::~CNormalUser()
{
}

void CNormalUser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNormalUser, CDialog)
END_MESSAGE_MAP()

BOOL CNormalUser::OnInitDialog()
{
	CDialog::OnInitDialog();
	return TRUE;
}


// CNormalUser message handlers
