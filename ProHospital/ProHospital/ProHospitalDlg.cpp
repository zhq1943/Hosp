
// ProHospitalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "ProHospital.h"
#include "ProHospitalDlg.h"
#include "afxdialogex.h"
#include "CDatabaseCon.h"
#include "CUser.h"
#include "DlgUser.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define  CONDATA UString(L"F:\\test\\newe.mdb")
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CProHospitalDlg dialog




CProHospitalDlg::CProHospitalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProHospitalDlg::IDD, pParent)
	, m_username(_T(""))
	, m_userpass(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProHospitalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USER, m_username);
	DDX_Text(pDX, IDC_EDIT_MIMA, m_userpass);
}

BEGIN_MESSAGE_MAP(CProHospitalDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CProHospitalDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CProHospitalDlg message handlers

BOOL CProHospitalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
// 	CDatabaseCon con;
// 
// 	bool res = con.Connect_(2003, UString(L"F:\\test\\newe.mdb"), UString(L""), UString(L""));
// 	
// 	if (!res)
// 	{
// 		AfxMessageBox(L"连接数据库失败！");
// 		con_ok = FALSE;
// 	}else
// 	{
// 		con_ok = TRUE;
// 	}
// 
// 	res = con.ExecuteSql(UString(L"SELECT * FROM UpdateData"));
// 	UString name = con.GetValueStr(UString(L"NameStore"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProHospitalDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProHospitalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProHospitalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProHospitalDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CUser user;
	bool res_ = user.CheckUser(wstring(m_username), wstring(m_userpass));
	if (res_)
	{
// 		CString per_num;
// 		per_num.Format(L"%d", user.GetPer());
// 		AfxMessageBox(per_num);
		CDlgUser dlg(user, NULL);
		dlg.DoModal();

	}else
	{
		
		AfxMessageBox(L"用户名或密码错误！！");
	}
}
