#include "stdafx.h"
#include "CUser.h"

wstring database_ = L".\\newe.mdb";
CUser::CUser()
{
	per = -1;
	
}

CUser::CUser(CUser& user_)
{
	per = user_.GetPer();
	user_name = user_.GetUserName_();
	passworld = user_.GetPass();
}

CUser::~CUser()
{

}


bool CUser::CheckUser( wstring _name, wstring _password )
{
	if (_name.empty())
	{
		return false;
	}

	if (_password.empty())
	{
		return false;
	}

	user_name = _name;

	CDatabaseCon con;

	bool res = con.Connect_(2003, wstring(L"F:\\test\\newe.mdb"), UString(L""), UString(L""));

	if (!res)
	{
		return false;
	}

	res = con.ExecuteSql(UString(L"SELECT * FROM UserTab"));
	if (!res)
	{
		return false;
	}

	if (!con.GoFirst())
	{
		return false;
	}
	while(!con.Eof())
	{
		UString name_ = con.GetValueStr(UString(L"User"));
		if (name_ == user_name)
		{
		    UString passwo = con.GetValueStr(UString(L"Password"));
			if (_password == passwo)
			{
				per = con.GetValueInt(UString(L"Promission"));
				con.Close_();
				return true;
			}else
			{
				con.Close_();
				return false;
			}
		}

			con.NextRecord();
	}
	
	return false;
}
