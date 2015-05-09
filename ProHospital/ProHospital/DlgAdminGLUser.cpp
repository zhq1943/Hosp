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

	cpop_menu.LoadMenuW(IDR_MENU1);
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

	/*CPoint point;

	GetCursorPos(&point);
	GetDlgItem(IDC_LIST_USER)->ScreenToClient(&point);
	//m_usergl.ScreenToClient(&point);
	LVHITTESTINFO info;
	info.pt=point;
	info.flags=LVHT_TOLEFT ;
	m_usergl.SubItemHitTest(&info);
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
	menu.AppendMenu(MF_STRING,IDD_MENU_MODIINFO,L"刷新");
	menu.AppendMenu(MF_SEPARATOR);
	menu.AppendMenu(MF_STRING,IDD_DIALOG_SICKINFO,L"添加");	
	menu.AppendMenu(MF_SEPARATOR);
// 	menu.AppendMenu(MF_STRING,ID_MENUITEM_AMEND,"修改");
// 	menu.AppendMenu(MF_SEPARATOR);
// 	menu.AppendMenu(MF_STRING,ID_MENUITEM_DEL,"删除");
	CPoint p;
	::GetCursorPos(&p);
	menu.TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, p.x, p.y, this);
	menu.DestroyMenu();
}
