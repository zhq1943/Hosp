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

	bool res = con.Connect_(2003, wstring(L".\\newe.mdb"), UString(L""), UString(L""));

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

bool CUser::GetUserInfo(UserInfoStru& stu_)
{
	return true;
}

std::string CUser::GetDataStr( wstring& table_, wstring& name )
{
	if (table_.empty())
	{
		return false;
	}

	if (name.empty())
	{
		return false;
	}

	
	CDatabaseCon con;

	bool res = con.Connect_(2003, wstring(L".\\newe.mdb"), UString(L""), UString(L""));

	if (!res)
	{
		return false;
	}

	wstring search_str = L"select * from ";
	search_str += table_;
	search_str += L" where UserName = ";
	search_str += user_name;

	res = con.ExecuteSql(search_str);
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
         
	}

	return false;
}

bool CUser::GetDatavector( wstring& tabel_, wstring& name, wstring& key, vector<wstring>& all_str )
{
// 	if (tabel_.empty())
// 	{
// 		return false;
// 	}
// 
// 	if (name.empty())
// 	{
// 		return false;
// 	}
// 
// 	if (key.empty())
// 	{
// 		return false;
// 	}
// 
// 
// 	CDatabaseCon con;
// 
// 	bool res = con.Connect_(2003, wstring(L".\\newe.mdb"), UString(L""), UString(L""));
// 
// 	if (!res)
// 	{
// 		return false;
// 	}
// 
// 	wstring search_str = L"select * from ";
// 	search_str += tabel_;
// 	search_str += L" where ";
// 	search_str += name;
// 	search_str += L" = ";
// 	search_str += L"'";
// 	search_str += key;
// 	search_str += L"'";
// 
// 	res = con.ExecuteSql(search_str);
// 	if (!res)
// 	{
// 		return false;
// 	}
// 
// 	if (!con.GoFirst())
// 	{
// 		return false;
// 	}
// 	while(!con.Eof())
// 	{
// 		UString name_ = con.GetValueStr(UString(L"User"));
// 		if (name_ == user_name)
// 		{
// 			UString passwo = con.GetValueStr(UString(L"Password"));
// 			if (_password == passwo)
// 			{
// 				per = con.GetValueInt(UString(L"Promission"));
// 				con.Close_();
// 				return true;
// 			}else
// 			{
// 				con.Close_();
// 				return false;
// 			}
// 		}
// 
// 		con.NextRecord();
// 	}
// 
	return false;
}

NormalUser::NormalUser()
{

}

NormalUser::NormalUser( const NormalUser& )
{

}

NormalUser::NormalUser( CUser& user_)
{
	uname = user_.GetUserName_();
	per = user_.GetPer();
}

NormalUser::~NormalUser()
{

}

bool NormalUser::GetUserInfo( UserInfoStru& stru_)
{
	stru_.birthday = birthday;
	stru_.birthplace = birthplace;
	stru_.liveplace = liveplace;
	stru_.marrys = marrys;
	stru_.name = name;
	stru_.sex = sex;
	stru_.uname = uname;
	stru_.warkplace = warkplace;
	return true;
}

void NormalUser::GetSickInfo( UserSickInfo& stru_)
{
	stru_.name = name;
	stru_.badid = badid;
	stru_.hosid = hosid;
	stru_.incheck = incheck;
	stru_.medread = medread;
	stru_.mtalk = mtalk;
	stru_.nsick = nsick;
	stru_.outcheck = outcheck;
	stru_.pasid = pasid;
	stru_.patkb = patkb;
	stru_.timein = timein;
	stru_.timewrite = timewrite;
	stru_.ttalk = ttalk;
}



bool NormalUser::InitUserInfo()
{

	if (uname.empty())
	{
		return false;
	}

	CDatabaseCon con;

	bool res = con.Connect_(2003, wstring(L".\\newe.mdb"), UString(L""), UString(L""));

	if (!res)
	{
		return false;
	}

	wstring search_uinfo = wstring(L"SELECT * FROM UserInfo where User = '");
	search_uinfo += uname.c_str();
	search_uinfo += L"'";
	res = con.ExecuteSql(search_uinfo);
	if (!res)
	{
		return false;
	}

	if (!con.GoFirst())
	{
		return false;
	}
	try
	{
		//while(!con.Eof())
		{
			name = con.GetValueStr(wstring(L"UserName"));
			sex = con.GetValueStr(wstring(L"UserSex"));
			birthday = con.GetValueStr(wstring(L"UserBirth"));
			birthplace = con.GetValueStr(wstring(L"UserLive"));
			warkplace = con.GetValueStr(wstring(L"UserWork"));
			liveplace = con.GetValueStr(wstring(L"UserPlace"));
			marrys = con.GetValueStr(wstring(L"UserMarry"));
			//con.NextRecord();
		}
	}catch(_com_error e)
	{
		return false;
	}
	
	wstring search_med = wstring(L"SELECT * FROM UserMed where User = '");
	search_med += uname.c_str();
	search_med += L"'";
	res = con.ExecuteSql(search_med);
	if (!res)
	{
		return false;
	}

	if (!con.GoFirst())
	{
		return false;
	}

	try
	{
		//while(!con.Eof())
		{
			timein = con.GetValueStr(UString(L"Timein"));
			timewrite = con.GetValueStr(UString(L"Timeout"));
			patkb = con.GetValueStr(UString(L"Patkb"));
			badid = con.GetValueStr(UString(L"Badid"));
			hosid = con.GetValueStr(UString(L"Hosid"));
			pasid = con.GetValueStr(UString(L"Pasid"));
			ttalk = con.GetValueStr(UString(L"Ttalk"));
			mtalk = con.GetValueStr(UString(L"Mtalk"));
			nsick = con.GetValueStr(UString(L"Nsick"));
			incheck = con.GetValueStr(UString(L"Incheck"));
			outcheck = con.GetValueStr(UString(L"Outcheck"));
			// medread = con.GetValueStr(UString(L"Timein"));
			//con.NextRecord();
		}
	}catch(_com_error e)
	{
		return false;
	}
	

	wstring search_rec = wstring(L"SELECT * FROM UserMedRecord where User = '");
	search_rec += uname.c_str();
	search_rec += L"'";
	res = con.ExecuteSql(search_rec);
	if (!res)
	{
		return false;
	}

	if (!con.GoFirst())
	{
		return false;
	}

	try
	{
		while(!con.Eof())
		{
			wstring timestr = con.GetValueStr(wstring(L"Time"));
			wstring  rec = con.GetValueStr(wstring(L"Medrecord"));
			hosrecord.insert(make_pair(timestr, rec));
			con.NextRecord();
		}
	}catch(_com_error e)
	{
		return false;
	}
	
	return true;
}

void NormalUser::GetMedRecdVector(map<wstring, wstring>& allrec)
{
	allrec = hosrecord;
}




AdminUser::AdminUser()
{

}

AdminUser::AdminUser( const AdminUser& )
{

}

AdminUser::AdminUser( CUser& u)
{
	per = u.GetPer();
	name = u.GetUserName_();
}

AdminUser::~AdminUser()
{

}
