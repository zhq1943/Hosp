// DlgUser.cpp : implementation file
//

#include "stdafx.h"
#include "ProHospital.h"
#include "DlgUser.h"
#include "afxdialogex.h"
#include "NormalUser.h"


// CDlgUser dialog

IMPLEMENT_DYNAMIC(CDlgUser, CDialog)

CDlgUser::CDlgUser(CUser user,  CWnd* pParent /*=NULL*/)
	: CDialog(CDlgUser::IDD, pParent)
{
	userlogin = user;
}

CDlgUser::~CDlgUser()
{
}

void CDlgUser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabctrl);
}


BEGIN_MESSAGE_MAP(CDlgUser, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CDlgUser::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDOK, &CDlgUser::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgUser::OnBnClickedCancel)
END_MESSAGE_MAP()

BOOL CDlgUser::OnInitDialog()
{
	CDialog::OnInitDialog();

	CRect rc; 
	m_tabctrl.GetClientRect(&rc);
	rc.top  += 25;   
	rc.left +=  1;
	rc.bottom -= 1;
	rc.right -= 1; 	

	if (userlogin.GetPer() == 1)
	{
		aduser = userlogin;
		

		int index = m_tabctrl.GetItemCount();
		m_tabctrl.InsertItem(index, L"管理员信息");
		m_tabctrl.InsertItem(index+1, L"用户管理");
		//m_tabctrl.InsertItem(index+2, L"搜索");
		m_tabctrl.InsertItem(index+2, L"病历管理");
		m_tabctrl.InsertItem(index+3, L"入院记录管理");

		dlg_adminowner.Create(IDD_DIALOG_ADMINOWEN, GetDlgItem(IDD_DIALOG_ADMINOWEN));
		dlg_adminowner.SetParent(&m_tabctrl);
		dlg_adminowner.MoveWindow(&rc);
		dlg_adminowner.ShowWindow(true);
		dlg_adminowner.SetAdUser(&aduser);
		dlg_adminowner.SetInfo();

// 		dlg_admininfo.Create(IDD_DIALOG_ADMININFO, GetDlgItem(IDD_DIALOG_ADMININFO));
// 		dlg_admininfo.SetParent(&m_tabctrl);
// 		dlg_admininfo.MoveWindow(&rc);
// 		dlg_admininfo.ShowWindow(false);
// 		dlg_admininfo.SetAdmin_(&aduser);

		dlg_admingluser.Create(IDD_DIALOG_ADMINGLUSER, GetDlgItem(IDD_DIALOG_ADMINGLUSER));
		dlg_admingluser.SetParent(&m_tabctrl);
		dlg_admingluser.MoveWindow(&rc);
		dlg_admingluser.ShowWindow(false);
		aduser.GetUserLoginInfo(alluser);
		dlg_admingluser.SetInfo(alluser);
		dlg_admingluser.SetAdmin_(&aduser);

		dlg_sickinfo.Create(IDD_DIALOG_SICKINFO, GetDlgItem(IDD_DIALOG_SICKINFO));
		dlg_sickinfo.SetParent(&m_tabctrl);
		dlg_sickinfo.MoveWindow(&rc);
		dlg_sickinfo.ShowWindow(false);
		dlg_sickinfo.SetInfo((CUser*)&aduser);
		dlg_sickinfo.SetModify_();

		dlg_adminglsick.Create(IDD_DIALOG_ADMINGLSICK, GetDlgItem(IDD_DIALOG_ADMINGLSICK));
		dlg_adminglsick.SetParent(&m_tabctrl);
		dlg_adminglsick.MoveWindow(&rc);
		dlg_adminglsick.ShowWindow(false);
		dlg_adminglsick.SetSickInfo((CUser*)&aduser);

	}

	if (userlogin.GetPer() == 0)
	{
		NormalUser nuser;
		noruser = userlogin;
		nuser = userlogin;
		nuser.InitUserInfo();
		noruser.InitUserInfo();

		int index = m_tabctrl.GetItemCount();
		m_tabctrl.InsertItem(index,L"个人信息");
		m_tabctrl.InsertItem(index+1, L"病历单");
		m_tabctrl.InsertItem(index+2, L"入院记录");

		dlg_info.Create(IDD_DIALOG_USERSET, GetDlgItem(IDD_DIALOG_USERSET));
		dlg_info.SetParent(&m_tabctrl);
		dlg_info.MoveWindow(&rc);
		dlg_info.ShowWindow(true);
		dlg_info.SetInfo(noruser);

		dlg_sickinfo.Create(IDD_DIALOG_SICKINFO, GetDlgItem(IDD_DIALOG_SICKINFO));
		dlg_sickinfo.SetParent(&m_tabctrl);
		dlg_sickinfo.MoveWindow(&rc);
		dlg_sickinfo.ShowWindow(false);
		dlg_sickinfo.SetInfo((CUser*)&noruser);

		dlg_adminglsick.Create(IDD_DIALOG_ADMINGLSICK, GetDlgItem(IDD_DIALOG_ADMINGLSICK));
		dlg_adminglsick.SetParent(&m_tabctrl);
		dlg_adminglsick.MoveWindow(&rc);
		dlg_adminglsick.ShowWindow(false);
		dlg_adminglsick.SetSickInfo((CUser*)&noruser);

	}
	

	m_tabctrl.SetCurSel(0);

	return TRUE;
}


// CDlgUser message handlers


void CDlgUser::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;

	int nNewSel = m_tabctrl.GetCurSel();
	if (userlogin.GetPer() == 0)
	{
		if (nNewSel == 0)
		{
			dlg_info.ShowWindow(true);
			dlg_sickinfo.ShowWindow(false);
			dlg_adminglsick.ShowWindow(false);
		}

		if (nNewSel == 1)
		{
			dlg_sickinfo.ShowWindow(true);
			dlg_info.ShowWindow(false);
			dlg_adminglsick.ShowWindow(false);
		}

		if (nNewSel == 2)
		{
			dlg_sickinfo.ShowWindow(false);
			dlg_info.ShowWindow(false);
			dlg_adminglsick.ShowWindow(true);
		}
	}

	if (userlogin.GetPer() == 1)
	{

		if (updateinfo == true)
		{
			aduser.cur_nuser.InitUserInfo();
			dlg_sickinfo.SetInfo((CUser*)&aduser);
			updateinfo = false;
		}

		if (updatesick == true)
		{
			aduser.cur_nuser.InitUserInfo();
			dlg_adminglsick.SetSickInfo((CUser*)&aduser);
			updatesick = false;
		}
		if (nNewSel == 0)
		{
			dlg_adminowner.ShowWindow(true);
			dlg_admingluser.ShowWindow(false);
			//dlg_admininfo.ShowWindow(false);
			dlg_sickinfo.ShowWindow(false);
			dlg_adminglsick.ShowWindow(false);
		}

		if (nNewSel == 1)
		{
			dlg_adminowner.ShowWindow(false);
			dlg_admingluser.ShowWindow(true);
			//dlg_admininfo.ShowWindow(false);
			dlg_sickinfo.ShowWindow(false);
			dlg_adminglsick.ShowWindow(false);
		}

		if (nNewSel == 2)
		{
			dlg_adminowner.ShowWindow(false);
			dlg_admingluser.ShowWindow(false);
			//dlg_admininfo.ShowWindow(true);
			dlg_sickinfo.ShowWindow(true);
			dlg_adminglsick.ShowWindow(false);
		}

		if (nNewSel == 3)
		{
			dlg_adminowner.ShowWindow(false);
			dlg_admingluser.ShowWindow(false);
			//dlg_admininfo.ShowWindow(false);
			dlg_sickinfo.ShowWindow(false);
			dlg_adminglsick.ShowWindow(true);
		}

// 		if (nNewSel == 4)
// 		{
// 			dlg_adminowner.ShowWindow(false);
// 			dlg_admingluser.ShowWindow(false);
// 			dlg_admininfo.ShowWindow(false);
// 			dlg_sickinfo.ShowWindow(false);
// 			dlg_adminglsick.ShowWindow(true);
// 		}
	}
	
}


void CDlgUser::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialog::OnOK();
	if (userlogin.GetPer() == 1)
	{
		dlg_adminglsick.RestData();
		dlg_admingluser.RestData();
	}

	//dlg_admininfo.RestData();

}


void CDlgUser::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
