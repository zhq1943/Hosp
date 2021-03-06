#include "stdafx.h"
#include "CDatabaseCon.h"
CDatabaseCon::CDatabaseCon()
{
	m_Connptr = NULL;
	m_RecSet = NULL;

// 	if(AfxOleInit())
// 	{
// 		iniole = true;
// 	}else
// 	{
// 		iniole = false;
// 	}
}

CDatabaseCon::~CDatabaseCon()
{
	try
	{
		m_RecSet->Close();
		m_RecSet.Release();
	}catch(...)
	{
		m_RecSet = NULL;
	}

	Close_();
}

UString CDatabaseCon::GetValueStr( UString& name )
{
	_variant_t v;
	try
	{
		v =( m_RecSet->GetCollect(name.c_str()));
	}catch(_com_error e)
	{
		e.ErrorMessage();
	}
	
	return (wchar_t*)(_bstr_t)v;
}

int CDatabaseCon::GetValueInt( UString& name )
{
	_variant_t v =( m_RecSet->GetCollect(name.c_str()));
	if (v.vt == VT_NULL)
	{
		return 0;
	}
	return (int)v;
}

float CDatabaseCon::GetValueFlo( UString& name )
{

	_variant_t v =( m_RecSet->GetCollect(name.c_str()));
	if (v.vt == VT_NULL)
	{
		return 0.0f;
	}
	return (float)v;
}

bool CDatabaseCon::NextRecord()
{
	return SUCCEEDED(m_RecSet->MoveNext());
}

bool CDatabaseCon::Eof()
{
	return m_RecSet->adoEOF;
}

bool CDatabaseCon::Connect_(int ver, UString& datapos, UString& username, UString& password)
{
	if (!iniole)
	{
		return iniole;
	}

	try
	{
		HRESULT hr = S_OK;
		hr = m_Connptr.CreateInstance(_uuidof(Connection));
		if (FAILED(hr))
		{
			return false;
		}

		UString constr = GetConnectStr(ver, datapos, username,password);

		if (SUCCEEDED(m_Connptr->Open(_bstr_t(constr.c_str()), _T(""), _T(""), adConnectUnspecified)))
		{
			return true;
		}
	}
	catch (_com_error e)
	{
		e.ErrorMessage();
		return false;
	}
	catch (CFileException* e)
	{
	}
	catch (CException* e)
	{
	}

	return false;
}

bool CDatabaseCon::Close_()
{
	try
	{
		m_Connptr->Close();
		m_Connptr.Release();
	}catch(_com_error e)
	{
		e.ErrorMessage();
		return false;
	}

	return true;
}

UString CDatabaseCon::GetConnectStr( int ver, UString& datapos, UString& username, UString& password )
{
	UString connect_str;
	switch (ver)
	{
	case 2003:
		//connect_str.Format((L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;Jet OLEDB:Database Password=%s;Persist Security Info=False"),datapos.c_str(),password.c_str());
        connect_str = L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=";
		connect_str = ((connect_str + datapos)+L";Jet OLEDB:Database Password=")+password+L";Persist Security Info=False";
		break;
	case 2007:
		//这个链接字符串是没有密码的，有密码的需要测试一下
		//connect_str.Format(_T("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=%s;Persist Security Info=False;"),filepath.c_str());
		break;
	}
	return connect_str;
}

bool CDatabaseCon::ExecuteSql( UString& sql )
{
	m_RecSet.CreateInstance(__uuidof(Recordset));
	//查询
	HRESULT hr;
	try
	{
		hr = m_RecSet->Open(sql.c_str(),m_Connptr.GetInterfacePtr(),adOpenStatic,adLockOptimistic,adCmdText);
		if (SUCCEEDED(hr))
		{
			return TRUE;
		}else
		{
			return FALSE;
		}
	}
	catch (_com_error e)
	{
		e.ErrorMessage();
		return false;
	}

	return true;
}

bool CDatabaseCon::GoFirst()
{
	if(!m_RecSet->BOF) 
	{
		m_RecSet->MoveFirst(); 
	    return true;
	}
	else  
	{  
		return false;  
	}  
}

bool CDatabaseCon::SetValueStr( UString& key, UString& val )
{
	try
	{
		m_RecSet->PutCollect((_bstr_t)key.c_str(), (_bstr_t)val.c_str());
	}catch(_com_error e)
	{
		return false;
	}
}

bool CDatabaseCon::UpdateOk()
{
	try
	{
		m_RecSet->Update();

	}catch(_com_error e)
	{
		return false;
	}
}

bool CDatabaseCon::SetValueInt( UString& key, int i )
{
	try
	{
		m_RecSet->PutCollect((_bstr_t)key.c_str(), (_bstr_t)i);
	}catch(_com_error e)
	{
		return false;
	}
}

bool CDatabaseCon::NewRecord()
{
	try
	{
		m_RecSet->AddNew();
	}catch(_com_error e)
	{
		return false;
	}
}

bool CDatabaseCon::DelCurrentRec()
{
	try
	{
		m_RecSet->Delete(adAffectCurrent);
	}catch(_com_error e)
	{
		return false;
	}

	return true;
}


UString HelpFun::FormattoUStr( const char* str,... )
{
	std::string m_str = std::string(str);
	return L"";
}

