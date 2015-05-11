// DlgSickinfo.cpp : implementation file
//

#include "stdafx.h"
#include "ProHospital.h"
#include "DlgSickinfo.h"
#include "afxdialogex.h"


// CDlgSickinfo dialog

IMPLEMENT_DYNAMIC(CDlgSickinfo, CDialog)

CDlgSickinfo::CDlgSickinfo(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSickinfo::IDD, pParent)
	, m_name(_T(""))
	, m_timein(_T(""))
	, m_timeout(_T(""))
	, m_patkb(_T(""))
	, m_badid(_T(""))
	, m_hosid(_T(""))
	, m_pasid(_T(""))
	, m_ttalk(_T(""))
	, m_mtalk(_T(""))
	, m_nsick(_T(""))
	, m_outcheck(_T(""))
	, m_vincheck(_T(""))
{

}

CDlgSickinfo::~CDlgSickinfo()
{
}

void CDlgSickinfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_timein);
	DDX_Text(pDX, IDC_EDIT4, m_timeout);
	DDX_Text(pDX, IDC_EDIT5, m_patkb);
	DDX_Text(pDX, IDC_EDIT6, m_badid);
	DDX_Text(pDX, IDC_EDIT7, m_hosid);
	DDX_Text(pDX, IDC_EDIT8, m_pasid);
	DDX_Text(pDX, IDC_EDIT9, m_ttalk);
	DDX_Text(pDX, IDC_EDIT13, m_mtalk);
	DDX_Text(pDX, IDC_EDIT12, m_nsick);
	DDX_Control(pDX, IDC_EDIT11, m_incheck);
	DDX_Text(pDX, IDC_EDIT10, m_outcheck);
	DDX_Text(pDX, IDC_EDIT11, m_vincheck);
}


BEGIN_MESSAGE_MAP(CDlgSickinfo, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_MODISICKINFO, &CDlgSickinfo::OnBnClickedButtonModisickinfo)
END_MESSAGE_MAP()

void CDlgSickinfo::SetInfo( CUser* user_)
{
	NormalUser* nor_user = NULL;

	AdminUser* adu = dynamic_cast<AdminUser*>(user_);
	if (adu)
	{
		nor_user = &(adu->cur_nuser);
	}else
	{
		nor_user = dynamic_cast<NormalUser*>(user_);
	}

	if (nor_user)
	{

		UserSickInfo sick;
		nor_user->GetSickInfo(sick);
		user_name = sick.uname;
		m_name = sick.name.c_str();
		m_timein = sick.timein.c_str();
		m_timeout = sick.timewrite.c_str();
		m_patkb = sick.patkb.c_str();
		m_badid = sick.badid.c_str();
		m_hosid = sick.hosid.c_str();
		m_pasid = sick.pasid.c_str();
		m_ttalk = sick.ttalk.c_str();
		m_mtalk = sick.mtalk.c_str();
		m_nsick = sick.nsick.c_str();
		m_vincheck = sick.incheck.c_str();
		m_outcheck = sick.outcheck.c_str();
		UpdateData(FALSE);

	}
}


// CDlgSickinfo message handlers


void CDlgSickinfo::OnBnClickedButtonModisickinfo()
{
	// TODO: Add your control notification handler code here
	UpdateData();

	UserSickInfo sick;
	sick.name = m_name ;
	sick.timein  = m_timein;
	sick.timewrite  = m_timeout;
	sick.patkb  = m_patkb;
	sick.badid  = m_badid;
	sick.hosid   = m_hosid;
	sick.pasid  = m_pasid;
	sick.ttalk  = m_ttalk;
	sick.mtalk  = m_mtalk;
	sick.nsick  = m_nsick;
	sick.incheck  = m_vincheck;
	sick.outcheck  = m_outcheck;
	sick.uname = user_name;
	sick.ntalk = L"未知";

	  AdminUser ad;
	  bool res = ad.UpdateNorSick(sick);
	  if (res)
	  {
		  AfxMessageBox(L"添加成功！");
	  }else
	  {
		  AfxMessageBox(L"添加失败！");
	  }
}

void CDlgSickinfo::SetModify_()
{
	GetDlgItem(IDC_BUTTON_MODISICKINFO)->ShowWindow(TRUE);
}
