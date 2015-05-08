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
END_MESSAGE_MAP()

BOOL CDlgUser::OnInitDialog()
{
	CDialog::OnInitDialog();

	CRect rc; 
	m_tabctrl.GetClientRect(&rc);
	rc.top  += 20;   
	rc.left +=  1;
	rc.bottom -= 1;
	rc.right -= 1; 	

	if (userlogin.GetPer() == 1)
	{
		int index = m_tabctrl.GetItemCount();
		m_tabctrl.InsertItem(index, L"����Ա��Ϣ");
		m_tabctrl.InsertItem(index+1, L"�û�����");
		m_tabctrl.InsertItem(index+2, L"��������");

		dlg_admininfo.Create(IDD_DIALOG_ADMININFO, GetDlgItem(IDD_DIALOG_ADMININFO));
		dlg_admininfo.SetParent(&m_tabctrl);
		dlg_admininfo.MoveWindow(&rc);
		dlg_admininfo.ShowWindow(true);

		dlg_admingluser.Create(IDD_DIALOG_ADMINGLUSER, GetDlgItem(IDD_DIALOG_ADMINGLUSER));
		dlg_admingluser.SetParent(&m_tabctrl);
		dlg_admingluser.MoveWindow(&rc);
		dlg_admingluser.ShowWindow(false);

		dlg_adminglsick.Create(IDD_DIALOG_ADMINGLUSER, GetDlgItem(IDD_DIALOG_ADMINGLUSER));
		dlg_adminglsick.SetParent(&m_tabctrl);
		dlg_adminglsick.MoveWindow(&rc);
		dlg_adminglsick.ShowWindow(false);


	}

	if (userlogin.GetPer() == 0)
	{
		int index = m_tabctrl.GetItemCount();
		m_tabctrl.InsertItem(index,L"������Ϣ");
		m_tabctrl.InsertItem(index+1, L"������");

		dlg_info.Create(IDD_DIALOG_USERSET, GetDlgItem(IDD_DIALOG_USERSET));
		dlg_info.SetParent(&m_tabctrl);
		dlg_info.MoveWindow(&rc);
		dlg_info.ShowWindow(true);

		dlg_sickinfo.Create(IDD_DIALOG_SICKINFO, GetDlgItem(IDD_DIALOG_SICKINFO));
		dlg_sickinfo.SetParent(&m_tabctrl);
		dlg_sickinfo.MoveWindow(&rc);
		dlg_sickinfo.ShowWindow(false);

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
		}

		if (nNewSel == 1)
		{
			dlg_sickinfo.ShowWindow(true);
			dlg_info.ShowWindow(false);
		}
	}

	if (userlogin.GetPer() == 1)
	{
		if (nNewSel == 0)
		{
			dlg_admininfo.ShowWindow(true);
			dlg_admingluser.ShowWindow(false);
			dlg_adminglsick.ShowWindow(false);
		}

		if (nNewSel == 1)
		{
			dlg_admininfo.ShowWindow(false);
			dlg_admingluser.ShowWindow(true);
			dlg_adminglsick.ShowWindow(false);
		}

		if (nNewSel == 2)
		{
			dlg_admininfo.ShowWindow(false);
			dlg_admingluser.ShowWindow(false);
			dlg_adminglsick.ShowWindow(true);
		}
	}
	
}


void CDlgUser::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
