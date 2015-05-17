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
	ON_BN_CLICKED(IDC_BUTTON_DELREC, &CDlgAdminGLSick::OnBnClickedButtonDelrec)
	ON_CBN_SELCHANGE(IDC_COMBO1_TIMEGLSICK, &CDlgAdminGLSick::OnCbnSelchangeCombo1Timeglsick)
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
		AfxMessageBox(L"修改成功");
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
	int index_ = m_combo_time.GetCurSel();
	if (index_-1 < 0)
	{
		return;
	}
	index_ -= 1;
	m_combo_time.SetCurSel(index_);


	UpdateData(FALSE);

	CString time_comb;
	m_combo_time.GetWindowTextW(time_comb);

	GetRecordbyTime(wstring(time_comb));
}


void CDlgAdminGLSick::OnBnClickedButtonNext()
{
	// TODO: Add your control notification handler code here
	int index_ = m_combo_time.GetCurSel();
	if (index_ +1 > m_combo_time.GetCount() -1)
	{
		return;
	}

	index_ += 1;
	m_combo_time.SetCurSel(index_);

	UpdateData(FALSE);

	CString time_comb;
	m_combo_time.GetWindowTextW(time_comb);

	GetRecordbyTime(wstring(time_comb));
	
}

void CDlgAdminGLSick::SetSickInfo( CUser* user_)
{
	NormalUser* user = NULL;
		
		 aduser = dynamic_cast<AdminUser*>(user_);
		if (aduser)
		{
			user = &(aduser->cur_nuser);
			GetDlgItem(IDD_BUTTON_MODIFY)->ShowWindow(TRUE);
			GetDlgItem(IDD_BUTTON_CREATE)->ShowWindow(TRUE);
			GetDlgItem(IDC_BUTTON_DELREC)->ShowWindow(TRUE);
		}else
		{
			user = dynamic_cast<NormalUser*>(user_);
		}
		

	if (user)
	{
		m_uname_ = user->GetUserName_().c_str();
		if (m_uname_.IsEmpty())
		{
			return ;
		}
		UserInfoStru ustr;
		user->GetUserInfo(ustr);
		m_urname = ustr.name.c_str();
		map<wstring , wstring> all_rec;
		user->GetMedRecdVector(all_rec);
		user->GetMedRecdVector(all_record);
		
		wstring time_;
		m_combo_time.ResetContent();
		for (map<wstring, wstring>::iterator itor = all_record.begin();
			itor != all_record.end();
			itor++)
		{
		    time_ = (*itor).first;
			m_combo_time.AddString(time_.c_str());
			m_sickrecord = (*itor).second.c_str();
		}

		UpdateData(FALSE);
		if (m_combo_time.GetCount() != 0)
		{

			m_combo_time.SetCurSel(0);
			map<wstring, wstring>::iterator itor_ = all_record.find(wstring(time_));
			if (itor_ != all_record.end())
			{
				wstring rec_str = (*itor_).second;
				m_sickrecord = rec_str.c_str();
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

BOOL CDlgAdminGLSick::OnInitDialog()
{
	CDialog::OnInitDialog();
	

	return TRUE;
}


void CDlgAdminGLSick::OnBnClickedButtonDelrec()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	AdminUser user;
	CString time_;
	m_combo_time.GetWindowTextW(time_);
	bool res = user.DelRecByNT(wstring(m_uname_), wstring(time_));
	if (res)
	{
		AfxMessageBox(L"删除成功");
	}else
	{
		AfxMessageBox(L"删除失败");
	}
}


void CDlgAdminGLSick::OnCbnSelchangeCombo1Timeglsick()
{
	// TODO: Add your control notification handler code here
	int ind = m_combo_time.GetCurSel();
	CString time_;
	//m_combo_time.GetWindowTextW(time_);
	m_combo_time.GetLBText(ind, time_);

	GetRecordbyTime(wstring(time_));
}

void CDlgAdminGLSick::RestData()
{
	m_combo_time.ResetContent();
	m_sickrecord = L"";
	m_uname_ = L"";
	m_urname = L"";
	UpdateData(FALSE);

}
