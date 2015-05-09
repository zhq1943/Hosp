// DlgAdminGLSick.cpp : implementation file
//

#include "stdafx.h"
#include "ProHospital.h"
#include "DlgAdminGLSick.h"
#include "afxdialogex.h"



// CDlgAdminGLSick dialog

IMPLEMENT_DYNAMIC(CDlgAdminGLSick, CDialog)

CDlgAdminGLSick::CDlgAdminGLSick(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAdminGLSick::IDD, pParent)
	, m_username(_T(""))
	, m_name(_T(""))
	, m_sickrec(_T(""))
{

}

CDlgAdminGLSick::~CDlgAdminGLSick()
{
}

void CDlgAdminGLSick::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Text(pDX, IDC_EDIT3, m_name);
	DDX_Control(pDX, IDC_COMBO1, m_time);
	DDX_Text(pDX, IDC_EDIT2, m_sickrec);
}


BEGIN_MESSAGE_MAP(CDlgAdminGLSick, CDialog)
	ON_BN_CLICKED(IDD_BUTTON_MODIFY, &CDlgAdminGLSick::OnBnClickedButtonModify)
	ON_BN_CLICKED(IDD_BUTTON_CREATE, &CDlgAdminGLSick::OnBnClickedButtonCreate)
	ON_BN_CLICKED(IDC_BUTTON_PER, &CDlgAdminGLSick::OnBnClickedButtonPer)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CDlgAdminGLSick::OnBnClickedButtonNext)
END_MESSAGE_MAP()


// CDlgAdminGLSick message handlers


void CDlgAdminGLSick::OnBnClickedButtonModify()
{
	// TODO: Add your control notification handler code here
}


void CDlgAdminGLSick::OnBnClickedButtonCreate()
{
	// TODO: Add your control notification handler code here
}


void CDlgAdminGLSick::OnBnClickedButtonPer()
{
	// TODO: Add your control notification handler code here
}


void CDlgAdminGLSick::OnBnClickedButtonNext()
{
	// TODO: Add your control notification handler code here
}

void CDlgAdminGLSick::SetSickInfo( CUser* user_)
{
	NormalUser* user = NULL;
	if (user_->GetPer() == 1)
	{
		GetDlgItem(IDD_BUTTON_MODIFY)->ShowWindow(TRUE);
		GetDlgItem(IDD_BUTTON_CREATE)->ShowWindow(TRUE);
		AdminUser* aduser = dynamic_cast<AdminUser*>(user_);
		if (aduser)
		{
			user = &(aduser->cur_nuser);
		}
		
	}

	if (user_->GetPer() == 0)
	{
		user = dynamic_cast<NormalUser*>(user_);
	}

	if (user)
	{
		m_username = user->GetUserName_().c_str();
		UserInfoStru ustr;
		user->GetUserInfo(ustr);
		m_name = ustr.name.c_str();
		map<wstring , wstring> all_rec;
		user->GetMedRecdVector(all_rec);
		for (map<wstring, wstring>::iterator itor = all_rec.begin();
			itor != all_rec.end();
			itor++)
		{
			wstring rec = (*itor).second;
			m_sickrec = rec.c_str();
		}
		
	}

	UpdateData(FALSE);
	
}