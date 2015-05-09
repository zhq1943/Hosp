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
END_MESSAGE_MAP()

void CDlgSickinfo::SetInfo( NormalUser& user_)
{
	UserSickInfo sick;
	user_.GetSickInfo(sick);

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


// CDlgSickinfo message handlers
