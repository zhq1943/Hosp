// DlgAdminGLUser.cpp : implementation file
//

#include "stdafx.h"
#include "ProHospital.h"
#include "DlgAdminGLUser.h"
#include "afxdialogex.h"

bool updateinfo = false;
bool updatesick = false;
// CDlgAdminGLUser dialog

IMPLEMENT_DYNAMIC(CDlgAdminGLUser, CDialog)

CDlgAdminGLUser::CDlgAdminGLUser(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAdminGLUser::IDD, pParent)
	, m_ed_searstr(_T(""))
{

}

CDlgAdminGLUser::~CDlgAdminGLUser()
{
}

void CDlgAdminGLUser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_USER, m_usergl);
	DDX_Control(pDX, IDC_COMBO_STYPE, m_cb_stype);
	DDX_Text(pDX, IDC_EDIT_NAME, m_ed_searstr);
}


BEGIN_MESSAGE_MAP(CDlgAdminGLUser, CDialog)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_USER, &CDlgAdminGLUser::OnNMDblclkListUser)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_USER, &CDlgAdminGLUser::OnNMRClickListUser)
	ON_COMMAND(32771, &CDlgAdminGLUser::On32771)
	ON_COMMAND(32772, &CDlgAdminGLUser::On32772)
	ON_COMMAND(IDD_MENU_DELUSER, &CDlgAdminGLUser::OnDelUser)
	ON_BN_CLICKED(IDOK, &CDlgAdminGLUser::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SEARCHUSER, &CDlgAdminGLUser::OnBnClickedButtonSearchuser)
	ON_NOTIFY(NM_CLICK, IDC_LIST_USER, &CDlgAdminGLUser::OnNMClickListUser)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgAdminGLUser::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL CDlgAdminGLUser::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_cb_stype.InsertString(0, L"姓名");
	m_cb_stype.InsertString(1, L"用户名");
	m_cb_stype.SetCurSel(1);

	RECT rc;
	m_usergl.GetClientRect(&rc);
	float wid = rc.right - rc.left;
	m_usergl.InsertColumn(0, L"用户名", LVCFMT_LEFT, wid/3);
	m_usergl.InsertColumn(1, L"姓名", LVCFMT_LEFT, wid/3);
	m_usergl.InsertColumn(2, L"最后登录时间", LVCFMT_LEFT, wid/3);

	admin_->GetUserLoginInfo(allinfo);
	//cpop_menu.LoadMenuW(IDR_MENU1);
	return true;
}

void CDlgAdminGLUser::SetInfo(vector<UserLoginfo>& alluser)
{
	m_usergl.DeleteAllItems();
	int i = 0;
	for (vector<UserLoginfo>::iterator itor = alluser.begin(); 
		 itor != alluser.end();
		 ++itor)
	{
		UserLoginfo userinfo = *itor;
		if (userinfo.per_ == 1)
		{
			continue;
		}
		m_usergl.InsertItem(i, userinfo.uname.c_str());
		m_usergl.SetItemText(i, 1, userinfo.name.c_str());
		m_usergl.SetItemText(i, 2, userinfo.lasttime.c_str());
	}
}




// CDlgAdminGLUser message handlers


void CDlgAdminGLUser::OnNMDblclkListUser(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

}


void CDlgAdminGLUser::OnNMRClickListUser(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

	if (pNMItemActivate->iItem < 0||pNMItemActivate->iSubItem <0)
	{
		return;
	}

	sel_user =  m_usergl.GetItemText(pNMItemActivate->iItem, pNMItemActivate->iSubItem);
	
	CMenu menu;
	menu.CreatePopupMenu();
	menu.AppendMenu(MF_STRING,IDD_MENU_MODIINFO,L"修改个人信息");
	menu.AppendMenu(MF_SEPARATOR);
	menu.AppendMenu(MF_STRING,32772,L"修改密码");	
	menu.AppendMenu(MF_SEPARATOR);
 	menu.AppendMenu(MF_STRING,IDD_MENU_DELUSER,L"删除用户");
 	menu.AppendMenu(MF_SEPARATOR);
// 	menu.AppendMenu(MF_STRING,ID_MENUITEM_DEL,"删除");
	CPoint p;
	::GetCursorPos(&p);
	menu.TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, p.x, p.y, this);
	menu.DestroyMenu();
}


void CDlgAdminGLUser::On32771()
{
	// TODO: Add your command handler code here
	NormalUser user;
	user.SetUserName_(wstring(sel_user));
	user.InitUserInfo();
	
	dlg_noruser.Create(IDD_DIALOG_USERSET, GetDlgItem(IDD_DIALOG_USERSET));
	dlg_noruser.SetInfo(user);
	dlg_noruser.SetModvis();
	dlg_noruser.ShowWindow(TRUE);
	
}


void CDlgAdminGLUser::On32772()
{
	// TODO: Add your command handler code here

	NormalUser user;
	user.SetUserName_(wstring(sel_user));
	user.InitUserInfo();
	UserLoginfo m_lginfo;
	user.GetLoginInfo(m_lginfo);
	dlg_mima.SetUName(sel_user);
	dlg_mima.SetUserLgInfo(m_lginfo);
	dlg_mima.DoModal();
}


void CDlgAdminGLUser::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialog::OnOK();
	if (sel_user.IsEmpty())
	{
		AfxMessageBox(L"选中要操作的用户");
		return;
	}


	admin_->cur_nuser.SetUserName_(wstring(sel_user));
	bool res = admin_->cur_nuser.InitUserInfo();
	if (res)
	{
		updateinfo = true;
		updatesick = true;
		AfxMessageBox(L"导出成功");
	}else
	{
		AfxMessageBox(L"导出失败");
	}
}

void CDlgAdminGLUser::RestData()
{
	m_usergl.DeleteAllItems();
	UpdateData(FALSE);
}


void CDlgAdminGLUser::OnBnClickedButtonSearchuser()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_usergl.DeleteAllItems();
	CString str_;
	m_cb_stype.GetWindowTextW(str_);
	//AdminUser admin;

	if (m_ed_searstr.IsEmpty())
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
			if (uinof.uname == wstring(m_ed_searstr))
			{
				m_usergl.InsertItem(i, m_ed_searstr);
				m_usergl.SetItemText(i, 1, uinof.name.c_str());
				m_usergl.SetItemText(i, 2, uinof.lasttime.c_str());
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
			if (uinof.name == wstring(m_ed_searstr))
			{
				m_usergl.InsertItem(i, uinof.uname.c_str());
				m_usergl.SetItemText(i, 1, uinof.name.c_str());
				m_usergl.SetItemText(i, 2, uinof.lasttime.c_str());
			}
		}
	}

	if (m_usergl.GetItemCount() == 0)
	{
		AfxMessageBox(L"未找到！");
	}
}

void CDlgAdminGLUser::OnDelUser()
{
	//AdminUser admin;
	bool res = admin_->DelUser(wstring(sel_user));
	if (res)
	{
		AfxMessageBox(L"删除成功");
	}else
	{
		AfxMessageBox(L"删除失败");
	}
}



void CDlgAdminGLUser::OnNMClickListUser(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

	if (pNMItemActivate->iItem != -1)
	{
		sel_user = m_usergl.GetItemText(pNMItemActivate->iItem, 0);
	}
}


void CDlgAdminGLUser::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	admin_->GetUserLoginInfo(allinfo);
	SetInfo(allinfo);
}
