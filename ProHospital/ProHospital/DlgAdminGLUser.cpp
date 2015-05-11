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
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_USER, &CDlgAdminGLUser::OnNMDblclkListUser)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_USER, &CDlgAdminGLUser::OnNMRClickListUser)
	ON_COMMAND(32771, &CDlgAdminGLUser::On32771)
	ON_COMMAND(32772, &CDlgAdminGLUser::On32772)
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
		m_usergl.SetItemText(i, 1, userinfo.password.c_str());
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
	
	/*CPoint point;

	::GetCursorPos(&point);
	GetDlgItem(IDC_LIST_USER)->ScreenToClient(&point);
	//m_usergl.ScreenToClient(&point);
	LVHITTESTINFO info;
	info.pt=point;
	info.flags=LVHT_ABOVE ;
	m_usergl.SubItemHitTest(&info);
	m_usergl.HitTest(point);
	if( info.iItem < 0 )
		return;
	//info.iItem,info.iSubItem 列表中第几行第几列
	if( 1 == info.iItem && 1 == info.iSubItem ) //在第二行，第二列显示菜单
	{
		GetCursorPos(&point);
		CMenu * pop_menu = cpop_menu.GetSubMenu( 0 );
		pop_menu->TrackPopupMenu(TPM_LEFTALIGN |TPM_RIGHTBUTTON, point.x, 
			point.y, this);
	}*/

	CMenu menu;
	menu.CreatePopupMenu();
	menu.AppendMenu(MF_STRING,IDD_MENU_MODIINFO,L"修改个人信息");
	menu.AppendMenu(MF_SEPARATOR);
	menu.AppendMenu(MF_STRING,32772,L"修改密码");	
	menu.AppendMenu(MF_SEPARATOR);
// 	menu.AppendMenu(MF_STRING,ID_MENUITEM_AMEND,"修改");
// 	menu.AppendMenu(MF_SEPARATOR);
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
