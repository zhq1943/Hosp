// DlgAdminGLUser.cpp : implementation file
//

#include "stdafx.h"
#include "ProHospital.h"
#include "DlgAdminGLUser.h"
#include "afxdialogex.h"


// CDlgAdminGLUser dialog

IMPLEMENT_DYNAMIC(CDlgAdminGLUser, CDialog)

CDlgAdminGLUser::CDlgAdminGLUser(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAdminGLUser::IDD, pParent)
{

}

CDlgAdminGLUser::~CDlgAdminGLUser()
{
}

void CDlgAdminGLUser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_USER, m_usergl);
}


BEGIN_MESSAGE_MAP(CDlgAdminGLUser, CDialog)
END_MESSAGE_MAP()

BOOL CDlgAdminGLUser::OnInitDialog()
{
	CDialog::OnInitDialog();

	RECT rc;
	m_usergl.GetClientRect(&rc);
	float wid = rc.right - rc.left;
	m_usergl.InsertColumn(0, L"用户名", LVCFMT_LEFT, wid/3);
	m_usergl.InsertColumn(1, L"密码", LVCFMT_LEFT, wid/3);
	m_usergl.InsertColumn(2, L"最后登录时间", LVCFMT_LEFT, wid/3);
	return true;
}




// CDlgAdminGLUser message handlers
