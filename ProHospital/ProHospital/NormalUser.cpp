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
	, m_name(_T(""))
	, m_username(_T(""))
	, m_sex(_T(""))
	, m_birthday(_T(""))
	, m_hometown(_T(""))
	, m_warkplace(_T(""))
	, m_liveplace(_T(""))
	, m_ifmarry(_T(""))
{
	
}

CNormalUser::~CNormalUser()
{
}

void CNormalUser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_username);
	DDX_Text(pDX, IDC_EDIT_SEX, m_sex);
	DDX_Text(pDX, IDC_EDIT_BIRTHDAY, m_birthday);
	DDX_Text(pDX, IDC_EDIT_HOMETOWN, m_hometown);
	DDX_Text(pDX, IDC_EDIT_WORKPLACE, m_warkplace);
	DDX_Text(pDX, IDC_EDIT_LIVEPLACE, m_liveplace);
	DDX_Text(pDX, IDC_EDIT_MARRY, m_ifmarry);
}


BEGIN_MESSAGE_MAP(CNormalUser, CDialog)
END_MESSAGE_MAP()

BOOL CNormalUser::OnInitDialog()
{
	CDialog::OnInitDialog();
	return TRUE;
}

void CNormalUser::SetInfo(NormalUser& user_)
{
	UserInfoStru str_;
	user_.GetUserInfo(str_);

	m_name = str_.name.c_str();
	m_username = str_.uname.c_str();
	m_sex = str_.sex.c_str();
	m_birthday = str_.birthday.c_str();
	m_hometown = str_.birthplace.c_str();
	m_warkplace = str_.warkplace.c_str();
	m_liveplace = str_.liveplace.c_str();
	m_ifmarry = str_.marrys.c_str();

	UpdateData(FALSE);
}


// CNormalUser message handlers
