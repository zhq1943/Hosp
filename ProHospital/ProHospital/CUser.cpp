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
	stru_.ntalk =ntalk;
	stru_.mtalk = mtalk;
	stru_.nsick = nsick;
	stru_.outcheck = outcheck;
	stru_.pasid = pasid;
	stru_.patkb = patkb;
	stru_.timein = timein;
	stru_.timewrite = timewrite;
	stru_.ttalk = ttalk;
	stru_.uname = uname;
	stru_.ntalk = ntalk;
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

	wstring userinfo_s = wstring(L"select * from UserTab where User = '");
	userinfo_s += uname.c_str();
	userinfo_s += L"'";
	res = con.ExecuteSql(userinfo_s);
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
		uname = con.GetValueStr(wstring(L"User"));
		paword = con.GetValueStr(wstring(L"Password"));
		per = con.GetValueInt(wstring(L"Promission"));
		lastlgtime = con.GetValueStr(wstring(L"LastTime"));
	}catch(_com_error e)
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
		hosrecord.clear();
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

void NormalUser::GetLoginInfo( UserLoginfo& str_ )
{
	str_.lasttime = lastlgtime;
	str_.password = paword;
	str_.name = name;
	str_.per_ = per;
	str_.uname = uname;
}





AdminUser::AdminUser()
{

}

AdminUser::AdminUser( AdminUser& u)
{
	per = u.GetAdPer();
	name = u.GetAdName();
}

AdminUser::AdminUser( CUser& u)
	:CUser(u)
{
	per = u.GetPer();
	name = u.GetUserName_();
}

AdminUser::~AdminUser()
{

}

void AdminUser::GetUserLoginInfo( vector<UserLoginfo>& all )
{
	all.clear();
	CDatabaseCon con;

	bool res = con.Connect_(2003, wstring(L".\\newe.mdb"), UString(L""), UString(L""));

	if (!res)
	{
		return ;
	}

	wstring search_med = wstring(L"SELECT * FROM UserTab");

	res = con.ExecuteSql(search_med);
	if (!res)
	{
		return ;
	}

	if (!con.GoFirst())
	{
		return ;
	}

	try
	{
		UserLoginfo linfo;
		while(!con.Eof())
		{
			linfo.lasttime = con.GetValueStr(wstring(L"LastTime"));
			linfo.password = con.GetValueStr(wstring(L"Password"));
			linfo.uname = con.GetValueStr(wstring(L"User"));
			linfo.per_ = con.GetValueInt(wstring(L"Promission"));
			linfo.name = con.GetValueStr(wstring(L"UserName"));
			all.push_back(linfo);
			con.NextRecord();
		}
	}catch(_com_error e)
	{
		return ;
	}
}

bool AdminUser::UpdateNorUser( UserInfoStru& stru_ )
{
	
	CDatabaseCon con;

	bool res = con.Connect_(2003, wstring(L".\\newe.mdb"), UString(L""), UString(L""));

	if (!res)
	{
		return false;
	}

	wstring search_med = wstring(L"SELECT * FROM UserInfo");

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
		UserLoginfo linfo;
		while(!con.Eof())
		{
			wstring m_uname = con.GetValueStr(wstring(L"User"));
			if (m_uname == stru_.uname)
			{
				con.SetValueStr(wstring(L"UserName"), stru_.name);
				con.SetValueStr(wstring(L"UserSex"), stru_.sex);
				con.SetValueStr(wstring(L"UserBirth"), stru_.birthday);
				con.SetValueStr(wstring(L"UserPlace"), stru_.liveplace);
				con.SetValueStr(wstring(L"UserWork"), stru_.warkplace);
				con.SetValueStr(wstring(L"UserLive"), stru_.liveplace);
				con.SetValueStr(wstring(L"UserMarry"), stru_.marrys);
				con.UpdateOk();
				break;
			}
			
			con.NextRecord();
		}

		if (con.Eof())
		{
			con.NewRecord();
			con.SetValueStr(wstring(L"User"), stru_.uname);
			con.SetValueStr(wstring(L"UserName"), stru_.name);
			con.SetValueStr(wstring(L"UserSex"), stru_.sex);
			con.SetValueStr(wstring(L"UserBirth"), stru_.birthday);
			con.SetValueStr(wstring(L"UserPlace"), stru_.liveplace);
			con.SetValueStr(wstring(L"UserWork"), stru_.warkplace);
			con.SetValueStr(wstring(L"UserLive"), stru_.liveplace);
			con.SetValueStr(wstring(L"UserMarry"), stru_.marrys);
			con.UpdateOk();

		}
	}catch(_com_error e)
	{
		return false;
	}
}

bool AdminUser::UpdateNorLogin( UserLoginfo& stru_ )
{
	CDatabaseCon con;

	bool res = con.Connect_(2003, wstring(L".\\newe.mdb"), UString(L""), UString(L""));

	if (!res)
	{
		return false;
	}

	wstring search_med = wstring(L"SELECT * FROM UserTab");

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
		UserLoginfo linfo;
		while(!con.Eof())
		{
			
			wstring username = con.GetValueStr(wstring(L"User"));
			if (stru_.uname == username)
			{
				con.SetValueStr(wstring(L"Password"), stru_.password);
				con.SetValueInt(wstring(L"Promission"), stru_.per_);
				con.SetValueStr(wstring(L"Lasttime"), stru_.lasttime);
				con.SetValueStr(wstring(L"UserName"), stru_.name);
				con.UpdateOk();
				break;
			}

			con.NextRecord();
		}

		if (con.Eof())
		{
			con.NewRecord();
			con.SetValueStr(wstring(L"User"), stru_.uname);
			con.SetValueInt(wstring(L"Promission"), stru_.per_);
			con.SetValueStr(wstring(L"Lasttime"), stru_.lasttime);
			con.SetValueStr(wstring(L"Password"), stru_.password);
			con.SetValueStr(wstring(L"UserName"), stru_.name);
			con.UpdateOk();
		}
	}catch(_com_error e)
	{
		return false;
	}
}

bool AdminUser::UpdateNorSick( UserSickInfo& stru_ )
{
	CDatabaseCon con;

	bool res = con.Connect_(2003, wstring(L".\\newe.mdb"), UString(L""), UString(L""));

	if (!res)
	{
		return false;
	}

	wstring search_med = wstring(L"SELECT * FROM UserMed");

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
		UserLoginfo linfo;
		while(!con.Eof())
		{

			wstring username = con.GetValueStr(wstring(L"User"));
			if (stru_.uname == username)
			{
				con.SetValueStr(wstring(L"Timein"), stru_.timein);
				con.SetValueStr(wstring(L"Timeout"), stru_.timewrite);
				con.SetValueStr(wstring(L"Patkb"), stru_.patkb);
				con.SetValueStr(wstring(L"Badid"), stru_.badid);
				con.SetValueStr(wstring(L"Hosid"), stru_.hosid);
				con.SetValueStr(wstring(L"Pasid"), stru_.pasid);
				con.SetValueStr(wstring(L"Ttalk"), stru_.ttalk);
				con.SetValueStr(wstring(L"Mtalk"), stru_.mtalk);
				con.SetValueStr(wstring(L"Ntalk"), stru_.ntalk);
				con.SetValueStr(wstring(L"Nsick"), stru_.nsick);
				con.SetValueStr(wstring(L"Incheck"), stru_.incheck);
				con.SetValueStr(wstring(L"Outcheck"), stru_.outcheck);
				con.UpdateOk();
				break;
			}

			con.NextRecord();
		}

		if (con.Eof())
		{
			con.NewRecord();
			con.SetValueStr(wstring(L"User"), stru_.uname);
			con.SetValueStr(wstring(L"UserName"), stru_.name);
			con.SetValueStr(wstring(L"Timein"), stru_.timein);
			con.SetValueStr(wstring(L"Timeout"), stru_.timewrite);
			con.SetValueStr(wstring(L"Patkb"), stru_.patkb);
			con.SetValueStr(wstring(L"Badid"), stru_.badid);
			con.SetValueStr(wstring(L"Hosid"), stru_.hosid);
			con.SetValueStr(wstring(L"Pasid"), stru_.pasid);
			con.SetValueStr(wstring(L"Ttalk"), stru_.ttalk);
			con.SetValueStr(wstring(L"Mtalk"), stru_.mtalk);
			con.SetValueStr(wstring(L"Ntalk"), stru_.ntalk);
			con.SetValueStr(wstring(L"Nsick"), stru_.nsick);
			con.SetValueStr(wstring(L"Incheck"), stru_.incheck);
			con.SetValueStr(wstring(L"Outcheck"), stru_.outcheck);
			con.UpdateOk();
		}
	}catch(_com_error e)
	{
		return false;
	}
}

bool AdminUser::UpdateUserRecord( UserRecordInfo& stru_ )
{
	CDatabaseCon con;

	bool res = con.Connect_(2003, wstring(L".\\newe.mdb"), UString(L""), UString(L""));

	if (!res)
	{
		return false;
	}

	wstring search_med = wstring(L"SELECT * FROM UserMedRecord");

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
		bool modiok = false;
		UserLoginfo linfo;
		while(!con.Eof())
		{

			wstring username = con.GetValueStr(wstring(L"User"));
			wstring time_ = con.GetValueStr(wstring(L"time"));
			if (stru_.user_ == username&&stru_.time_ == time_)
			{
				con.SetValueStr(wstring(L"Medrecord"), stru_.record);
				modiok = true;
				con.UpdateOk();
				break;
			}

			con.NextRecord();
		}

		if (!modiok)
		{
			con.NewRecord();
			con.SetValueStr(wstring(L"User"), stru_.user_);
			con.SetValueStr(wstring(L"time"), stru_.time_);
			con.SetValueStr(wstring(L"Medrecord"), stru_.record);

			con.UpdateOk();
		}
	}catch(_com_error e)
	{
		return false;
	}
}

void AdminUser::GetSelfLoginInfo( UserLoginfo& u )
{
	vector<UserLoginfo> all;
	GetUserLoginInfo(all);
	for (vector<UserLoginfo>::iterator itor = all.begin();
		 itor != all.end();
		 itor++)
	{
		UserLoginfo uinfo = *itor;
		if (uinfo.uname == name)
		{
			u = uinfo;
			break;
		}
	}

}

bool AdminUser::DelRecByNT( wstring& name_, wstring& time_get )
{

	if (name_.empty())
	{
		return false;
	}

	if (time_get.empty())
	{
		return false;
	}
	CDatabaseCon con;

	bool res = con.Connect_(2003, wstring(L".\\newe.mdb"), UString(L""), UString(L""));

	if (!res)
	{
		return false;
	}

	wstring search_med = wstring(L"SELECT * FROM UserMedRecord");

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
		UserLoginfo linfo;
		while(!con.Eof())
		{

			wstring username = con.GetValueStr(wstring(L"User"));
			wstring time_ = con.GetValueStr(wstring(L"time"));
			if (time_get == wstring(L"ANY"))
			{
				if (name_ == username)
				{
					con.DelCurrentRec();
				}
			}else
			{
				if (name_ == username&&time_ == time_get)
				{
					con.DelCurrentRec();
					break;
				}
			}
			
			con.NextRecord();
		}

	}catch(_com_error e)
	{
		return false;
	}

	con.UpdateOk();
	return true;
}

bool AdminUser::DelUserInfo( wstring& uname )
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

	wstring search_med = wstring(L"SELECT * FROM UserInfo");

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
		UserLoginfo linfo;
		while(!con.Eof())
		{

			wstring username = con.GetValueStr(wstring(L"User"));
			if (uname == username)
			{
				con.DelCurrentRec();
				con.UpdateOk();
				break;
			}
			con.NextRecord();
		}

	}catch(_com_error e)
	{
		return false;
	}

	return true;
}

bool AdminUser::DelUser( wstring& uname )
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

	wstring search_med = wstring(L"SELECT * FROM UserTab");

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
		UserLoginfo linfo;
		while(!con.Eof())
		{

			wstring username = con.GetValueStr(wstring(L"User"));
			if (uname == username)
			{
				con.DelCurrentRec();
				con.UpdateOk();
				break;
			}
			con.NextRecord();
		}

	}catch(_com_error e)
	{
		return false;
	}

	return true;
}

bool AdminUser::DelUserSick( wstring &uname )
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

	wstring search_med = wstring(L"SELECT * FROM UserTab");

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
		UserLoginfo linfo;
		while(!con.Eof())
		{

			wstring username = con.GetValueStr(wstring(L"User"));
			if (uname == username)
			{
				con.DelCurrentRec();
				con.UpdateOk();
				break;
			}
			con.NextRecord();
		}

	}catch(_com_error e)
	{
		return false;
	}

	return true;
}

