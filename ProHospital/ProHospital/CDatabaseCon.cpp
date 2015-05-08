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
		//��������ַ�����û������ģ����������Ҫ����һ��
		//connect_str.Format(_T("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=%s;Persist Security Info=False;"),filepath.c_str());
		break;
	}
	return connect_str;
}

bool CDatabaseCon::ExecuteSql( UString& sql )
{
	m_RecSet.CreateInstance(__uuidof(Recordset));
	//��ѯ
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


UString HelpFun::FormattoUStr( const char* str,... )
{
	std::string m_str = std::string(str);
	return L"";
}

