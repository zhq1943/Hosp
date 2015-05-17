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
	NormalUser user;
	user.SetUserName_(cuser_->GetUserName_());
	user.InitUserInfo();

	
    nor_dlg.Create(IDD_DIALOG_USERSET, GetDlgItem(IDD_DIALOG_USERSET));
	nor_dlg.ModifyStyle(0,WS_CAPTION);
	nor_dlg.SetInfo(user);
	nor_dlg.SetModvis();
	nor_dlg.ShowWindow(TRUE);
}

BOOL CDlgAdminOwner::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	
	return TRUE;
}

void CDlgAdminOwner::SetInfo()
{
	UserLoginfo ulog;
	cuser_->GetSelfLoginInfo(ulog);
	wstring lgtime_str = L"上次登录时间: ";
	lgtime_str += ulog.lasttime;
	GetDlgItem(IDC_STATIC_ADLOGTIEM)->SetWindowTextW(lgtime_str.c_str());

	CString usercount = L"注册用户数: ";
	vector<UserLoginfo> allUser;
	cuser_->GetUserLoginInfo(allUser);
	int i = 0;
	for (vector<UserLoginfo>::iterator itor = allUser.begin();
		 itor != allUser.end();
		 itor++)
	{
		UserLoginfo uinfo = *itor;
		if (uinfo.per_ == 0)
		{
			i+= 1;
		}
	}
	usercount.Format(L"注册用户数: %d", i);
	GetDlgItem(IDC_STATIC_ALLUSERCOUNT)->SetWindowTextW(usercount);

	UserLoginfo userlog;
	cuser_->GetSelfLoginInfo(userlog);
	CTime time = CTime::GetCurrentTime(); 
	CString name_t = time.Format("%Y%m%d%H%M%S");//

	userlog.lasttime = wstring(name_t);
	cuser_->UpdateNorLogin(userlog);
}
