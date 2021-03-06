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
	, m_userrealname(_T(""))
{
	editsty = FALSE;
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
	DDX_Text(pDX, IDC_EDIT_REALNAME, m_userrealname);
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

	if (m_mima1 != m_mima2)
	{
		return;
	}

	if (editsty)
	{
		
		CTime time = CTime::GetCurrentTime();
		CString name_t = time.Format("%Y%m%d%H%M%S");
		m_lginfo.name = m_userrealname;
		m_lginfo.uname = m_username;
		m_lginfo.lasttime = name_t;
		m_lginfo.password = m_mima1;
		m_lginfo.per_ = 0;
		AdminUser aduser;
		bool res = aduser.UpdateNorLogin(m_lginfo);
		if (res)
		{
			
			//init userinfo
			UserInfoStru stru_info;
			stru_info.name = m_lginfo.name;
			stru_info.uname = m_lginfo.uname;
			bool res_ = aduser.UpdateNorUser(stru_info);

			UserSickInfo stru_sick;
			stru_sick.name = m_lginfo.name;
			stru_sick.uname = m_lginfo.uname;
			bool res = aduser.UpdateNorSick(stru_sick);

			UserRecordInfo stru_rec;
			stru_rec.time_ = m_lginfo.lasttime;
			stru_rec.user_ = m_lginfo.uname;
			aduser.UpdateUserRecord(stru_rec);

			AfxMessageBox(L"���ӳɹ�");
		}else
		{
			AfxMessageBox(L"����ʧ��");
		}
		
	}else
	{

		m_lginfo.password = m_mima1;
		AdminUser aduser;
		aduser.UpdateNorLogin(m_lginfo);
	}
	
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
	if (editsty)
	{

	}else
	{
		m_username = m_lginfo.uname.c_str();
		m_userrealname = m_lginfo.name.c_str();
		UpdateData(FALSE);   
	}

	GetDlgItem(IDC_EDIT2)->EnableWindow(editsty);
	GetDlgItem(IDC_EDIT_REALNAME)->EnableWindow(editsty);
	return TRUE;
}

void CDlgChangeMIMA::AddNewUser()
{
	//GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
	editsty = TRUE;
}

void CDlgChangeMIMA::ModifyMima()
{
	//GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
}
