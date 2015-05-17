// DlgAdminInfo.cpp : implementation file
//

#include "stdafx.h"
#include "ProHospital.h"
#include "DlgAdminInfo.h"
#include "afxdialogex.h"
#include "DlgSickinfo.h"
#include "DlgAdminGLSick.h"

// bool updateinfo = false;
// bool updatesick = false;
// CDlgAdminInfo dialog

IMPLEMENT_DYNAMIC(CDlgAdminInfo, CDialog)

CDlgAdminInfo::CDlgAdminInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAdminInfo::IDD, pParent)
	, m_ed_sstr(_T(""))
{

}

CDlgAdminInfo::~CDlgAdminInfo()
{
}

void CDlgAdminInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SEARTYPE, m_cb_stype);
	DDX_Text(pDX, IDC_EDIT_SEARSTR, m_ed_sstr);
	DDX_Control(pDX, IDC_LIST_SEARRES, m_lc_list);
}


BEGIN_MESSAGE_MAP(CDlgAdminInfo, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SEAR, &CDlgAdminInfo::OnBnClickedButtonSear)
	ON_BN_CLICKED(IDC_BUTTON_DCDATA, &CDlgAdminInfo::OnBnClickedButtonDcdata)
	ON_NOTIFY(NM_CLICK, IDC_LIST_SEARRES, &CDlgAdminInfo::OnNMClickListSearres)
END_MESSAGE_MAP()


// CDlgAdminInfo message handlers


void CDlgAdminInfo::OnBnClickedButtonSear()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_lc_list.DeleteAllItems();
	CString str_;
	m_cb_stype.GetWindowTextW(str_);
	AdminUser admin;

	if (m_ed_sstr.IsEmpty())
	{
		return;
	}

	if (str_ == L"用户名")
	{
		int i = 0;
		for (vector<UserLoginfo>::iterator itor = allinfo.begin();
			itor != allinfo.end();
			itor++)
		{
			UserLoginfo uinof = *itor;
			if (uinof.uname == wstring(m_ed_sstr))
			{
				m_lc_list.InsertItem(i, m_ed_sstr);
				m_lc_list.SetItemText(i, 1, uinof.name.c_str());
				m_lc_list.SetItemText(i, 2, uinof.lasttime.c_str());
			}
		}
	}

	if (str_ == L"姓名")
	{
		int i = 0;
		for (vector<UserLoginfo>::iterator itor = allinfo.begin();
			itor != allinfo.end();
			itor++)
		{
			UserLoginfo uinof = *itor;
			if (uinof.name == wstring(m_ed_sstr))
			{
				m_lc_list.InsertItem(i, m_ed_sstr);
				m_lc_list.SetItemText(i, 1, uinof.name.c_str());
				m_lc_list.SetItemText(i, 2, uinof.lasttime.c_str());
			}
		}
	}
	
	if (m_lc_list.GetItemCount() == 0)
	{
		AfxMessageBox(L"未找到！");
	}
}

BOOL CDlgAdminInfo::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_cb_stype.InsertString(0, L"姓名");
	m_cb_stype.InsertString(1, L"用户名");
	m_cb_stype.SetCurSel(1);
	RECT rc;
	m_lc_list.GetClientRect(&rc);
	float w = rc.right - rc.left;
	m_lc_list.InsertColumn(0, L"用户名", LVCFMT_LEFT, w/3);
	m_lc_list.InsertColumn(1, L"姓名", LVCFMT_LEFT, w/3);
	m_lc_list.InsertColumn(2, L"登录时间", LVCFMT_LEFT, w/3);

	admin_->GetUserLoginInfo(allinfo);

	return TRUE;

}


void CDlgAdminInfo::OnBnClickedButtonDcdata()
{
	// TODO: Add your control notification handler code here
// 	if (sel_user.IsEmpty())
// 	{
// 		AfxMessageBox(L"选中要操作的用户");
// 		return;
// 	}
// 
// 
// 	admin_->cur_nuser.SetUserName_(wstring(sel_user));
// 	bool res = admin_->cur_nuser.InitUserInfo();
// 	if (res)
// 	{
// 		updateinfo = true;
// 		updatesick = true;
// 	    AfxMessageBox(L"导出成功");
// 	}else
// 	{
// 		AfxMessageBox(L"导出失败");
// 	}

// 	HWND hw = ::GetDlgItem(this->GetParent()->GetSafeHwnd(), IDD_DIALOG_SICKINFO);
// 	CWnd* pwnd = CWnd::FromHandle(hw);
// 	CDlgSickinfo* psickinfo = dynamic_cast<CDlgSickinfo*>(pwnd);
// 	if (psickinfo)
// 	{
// 		psickinfo->SetInfo(admin_);
// 	}
// 
// 	hw = ::GetDlgItem(this->GetParent()->GetSafeHwnd(), IDD_DIALOG_ADMINGLSICK);
// 	pwnd = CWnd::FromHandle(hw);
// 	CDlgAdminGLSick* padglsick = dynamic_cast<CDlgAdminGLSick*>(pwnd);
// 	if (padglsick)
// 	{
// 		padglsick->SetSickInfo(admin_);
// 	}
}


void CDlgAdminInfo::OnNMClickListSearres(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	if (pNMItemActivate->iItem <0)
	{
		return;
	}
    sel_user =  m_lc_list.GetItemText(pNMItemActivate->iItem, 0);

}

void CDlgAdminInfo::RestData()
{
	m_lc_list.DeleteAllItems();
	m_ed_sstr = L"";
	//m_cb_stype.ResetContent();
	UpdateData(FALSE);
}
