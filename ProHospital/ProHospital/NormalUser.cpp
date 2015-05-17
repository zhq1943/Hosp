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
	ON_BN_CLICKED(IDC_BUTTON_ADMODIUSERINFO, &CNormalUser::OnBnClickedButtonAdmodiuserinfo)
	ON_BN_CLICKED(IDC_BUTTON_INFOOK, &CNormalUser::OnBnClickedButtonInfook)
	ON_WM_DESTROY()
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

	AdminUser aduser;
	UserLoginfo userlog;
	user_.GetLoginInfo(userlog);
	CTime time = CTime::GetCurrentTime(); 
	CString name_t = time.Format("%Y%m%d%H%M%S");//

	userlog.lasttime = wstring(name_t);
	aduser.UpdateNorLogin(userlog);

	UpdateData(FALSE);
}


// CNormalUser message handlers


void CNormalUser::OnBnClickedButtonAdmodiuserinfo()
{
	// TODO: Add your control notification handler code here
	UpdateData();

	UserInfoStru str_;

	 str_.name = m_name;
	 str_.uname = m_username;
	 str_.sex = m_sex;
	 str_.birthday = m_birthday;
	 str_.birthplace = m_hometown;
	 str_.warkplace = m_warkplace;
	 str_.liveplace = m_liveplace;
	str_.marrys = m_ifmarry;

	AdminUser ad;
	bool res = ad.UpdateNorUser(str_);
	if (res)
	{
		AfxMessageBox(L"修改成功");
	}else
	{
		AfxMessageBox(L"修改失败");
	}

}

void CNormalUser::SetModvis()
{
	GetDlgItem(IDC_BUTTON_ADMODIUSERINFO)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON_INFOOK)->ShowWindow(TRUE);

}


void CNormalUser::OnBnClickedButtonInfook()
{
	// TODO: Add your control notification handler code here
	OnOK();
    DestroyWindow();
}
void CNormalUser::OnDestroy()
{
	CDialog::OnDestroy();
	//delete this;
}