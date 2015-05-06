
#include "CUser.h"
CUser::CUser()
{
	per = -1;
}

CUser::CUser( const CUser& )
{

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

	bool res = con.Connect_(2003, database_, UString(L""), UString(L""));

	if (!res)
	{
		return false;
	}

	res = con.ExecuteSql(UString(L"SELECT * FROM UserLogin"));
	passworld = con.GetValueStr(user_name);

	if (passworld == _password)
	{
		per = con.GetValueInt(UString(L"Permission"));
		return true;
	}else
	{
		return false;
	}

}
