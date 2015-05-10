// DlgAdminGLSick.cpp : implementation file
//

#include "stdafx.h"
#include "ProHospital.h"
#include "DlgAdminGLSick.h"
#include "afxdialogex.h"



// CDlgAdminGLSick dialog

IMPLEMENT_DYNAMIC(CDlgAdminGLSick, CDialog)

CDlgAdminGLSick::CDlgAdminGLSick(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAdminGLSick::IDD, pParent)
	, m_uname_(_T(""))
	, m_urname(_T(""))
	, m_sickrecord(_T(""))
{
	aduser = NULL;
	ind = 0;
}

CDlgAdminGLSick::~CDlgAdminGLSick()
{
}

void CDlgAdminGLSick::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_UNAMEDLSICK, m_uname_);
	DDX_Text(pDX, IDC_EDIT_NAMEGLSICK, m_urname);
	DDX_Control(pDX, IDC_COMBO1_TIMEGLSICK, m_combo_time);
	DDX_Text(pDX, IDC_EDIT_RECORDGLSICK, m_sickrecord);
}


BEGIN_MESSAGE_MAP(CDlgAdminGLSick, CDialog)
	ON_BN_CLICKED(IDD_BUTTON_MODIFY, &CDlgAdminGLSick::OnBnClickedButtonModify)
	ON_BN_CLICKED(IDD_BUTTON_CREATE, &CDlgAdminGLSick::OnBnClickedButtonCreate)
	ON_BN_CLICKED(IDC_BUTTON_PER, &CDlgAdminGLSick::OnBnClickedButtonPer)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CDlgAdminGLSick::OnBnClickedButtonNext)
END_MESSAGE_MAP()


// CDlgAdminGLSick message handlers


void CDlgAdminGLSick::OnBnClickedButtonModify()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString text;
	UserRecordInfo usick;
	usick.user_ = m_uname_;
	m_combo_time.GetWindowTextW(text);
	usick.time_ = wstring(text);
	usick.record = m_sickrecord;
	bool res = aduser->UpdateUserRecord(usick);
	if (res)
	{
		AfxMessageBox(L"ÐÞ¸Ä³É¹¦");
	}else
	{
		AfxMessageBox(L"error");
	}
	
}


void CDlgAdminGLSick::OnBnClickedButtonCreate()
{
	// TODO: Add your control notification handler code here
	CTime time = CTime::GetCurrentTime();
	CString name_t = time.Format("%Y%m%d%H%M%S");
	m_combo_time.SetWindowTextW(name_t);
	m_sickrecord = L"";
	UpdateData(FALSE);
}


void CDlgAdminGLSick::OnBnClickedButtonPer()
{
	// TODO: Add your control notification handler code here
	if (ind-1 < 0)
	{
		return;
	}
	ind -= 1;
	m_combo_time.SetCurSel(ind);

	CString time_g = *((CString*)m_combo_time.GetItemData(ind));

	GetRecordbyTime(wstring(time_g));
}


void CDlgAdminGLSick::OnBnClickedButtonNext()
{
	// TODO: Add your control notification handler code here
	if (ind +1 > m_combo_time.GetCount() -1)
	{
		return;
	}

	ind += 1;
	m_combo_time.SetCurSel(ind);

	CString time_g = *((CString*)m_combo_time.GetItemData(ind));

	GetRecordbyTime(wstring(time_g));
	
}

void CDlgAdminGLSick::SetSickInfo( CUser* user_)
{
	NormalUser* user = NULL;
	if (user_->GetPer() == 1)
	{
		GetDlgItem(IDD_BUTTON_MODIFY)->ShowWindow(TRUE);
		GetDlgItem(IDD_BUTTON_CREATE)->ShowWindow(TRUE);
		 aduser = dynamic_cast<AdminUser*>(user_);
		if (aduser)
		{
			user = &(aduser->cur_nuser);
		}
		
	}

	if (user_->GetPer() == 0)
	{
		user = dynamic_cast<NormalUser*>(user_);
	}

	if (user)
	{
		m_uname_ = user->GetUserName_().c_str();
		UserInfoStru ustr;
		user->GetUserInfo(ustr);
		m_urname = ustr.name.c_str();
		map<wstring , wstring> all_rec;
		user->GetMedRecdVector(all_rec);
		user->GetMedRecdVector(all_record);
		for (map<wstring, wstring>::iterator itor = all_rec.begin();
			itor != all_rec.end();
			itor++)
		{
		//wstring rec = (*itor).second;
			wstring time_ = (*itor).first;
			//m_sickrec = rec.c_str();
			m_combo_time.AddString(time_.c_str());
			m_sickrecord = (*itor).second.c_str();
		}

		if (m_combo_time.GetCount() != 0)
		{

			m_combo_time.SetCurSel(0);
			m_combo_time.GetItemData(1);
			//CString time_g = *((CString*)(m_combo_time.GetItemData(1)));
			//map<wstring, wstring>::iterator itor_ = all_rec.find(wstring(time_g));
			//if (itor_ != all_rec.end())
			{
			//	wstring rec_str = (*itor_).second;
			//	m_sickrecord = rec_str.c_str();
			}
		}
		
		UpdateData(FALSE);
		
	}

	
	
}
void CDlgAdminGLSick::GetRecordbyTime( wstring ti_ )
{
	map<wstring, wstring>::iterator itor_ = all_record.find(wstring(ti_));
	if (itor_ != all_record.end())
	{
		wstring rec_str = (*itor_).second;
		m_sickrecord = rec_str.c_str();
	}
	UpdateData(FALSE);
}
