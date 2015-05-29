#pragma once
#include <iostream>
#include "CDatabaseCon.h"
#include <vector>
#include <map>
using namespace std;
extern wstring database_;

struct UserLoginfo
{
	wstring uname;
	wstring name;
	wstring password;
	wstring lasttime;
	int per_;
};

struct UserInfoStru
{
	wstring name;//name
	wstring sex;//usersex
	wstring birthday;//userbirth
	wstring birthplace;//userlive
	wstring warkplace;//userwork
	wstring liveplace;//userplace
	wstring marrys;//ifmarry
	wstring uname; //user

	UserInfoStru()
	{
		name = L"δ֪";
		uname = L"Unknow";
		sex = L"δ֪";
		birthday = L"δ֪";
		birthplace = L"δ֪";
		warkplace = L"δ֪";
		liveplace = L"δ֪";
		marrys = L"δ֪";
	}
};

struct UserSickInfo
{
	wstring uname;
	wstring name;
	wstring timein;
	wstring timewrite;
	wstring patkb;
	wstring badid;
	wstring hosid;
	wstring pasid;
	wstring ttalk;
	wstring mtalk;
	wstring nsick;
	wstring incheck;
	wstring outcheck;
	wstring ntalk;

	UserSickInfo()
	{
		name = L"δ֪";
		uname = L"Unknow";
		timein = L"δ֪";
		timewrite = L"δ֪";
		patkb = L"δ֪";
		badid = L"δ֪";
		hosid = L"δ֪";
		pasid =  L"δ֪";
		ttalk = L"δ֪";
		mtalk = L"δ֪";
		nsick = L"δ֪";
		incheck = L"δ֪";
		outcheck = L"δ֪";
		ntalk = L"δ֪";
	}
};

struct UserRecordInfo
{
	wstring time_;
	wstring user_;
	wstring record;

	UserRecordInfo()
	{
		time_ = L"unknow";
		user_ = L"unknow";
		record = L"�޼�¼";

	}
};
class CUser
{
public:
	CUser();
	CUser( CUser&);
	virtual ~CUser();

private:
	wstring user_name;

	wstring passworld;

	int per;

public:
	bool CheckUser(wstring name, wstring password);
	int GetPer()
	{
		return per;
	}

	virtual wstring GetUserName_()
	{
		return user_name;
	}

	wstring GetPass()
	{
		return passworld;
	}

	

	virtual bool GetUserInfo(UserInfoStru&);
	virtual string GetDataStr(wstring& table_, wstring& name);
	virtual bool  GetDatavector(wstring& tabel_, wstring& name, wstring& key, vector<wstring>& all_str);

};

class NormalUser:public CUser
{
public:
	NormalUser();
	NormalUser(const NormalUser&);
	NormalUser(CUser&);
	~NormalUser();
private:
	wstring name;
	int per;
	wstring lastlgtime;
	
	wstring sex;
	wstring birthday;
	wstring birthplace;
	wstring warkplace;
	wstring liveplace;
	wstring marrys;
	wstring paword;

	//
	wstring uname; //id

	//
	wstring timein;
	wstring timewrite;
	wstring patkb;
	wstring badid;
	wstring hosid;
	wstring pasid;
	wstring ttalk;
	wstring mtalk;
	wstring ntalk;
	wstring nsick;
	wstring incheck;

	wstring outcheck;
	wstring medread;

	map<wstring, wstring> hosrecord;

	

public:
	virtual bool InitUserInfo();
	virtual bool GetUserInfo(UserInfoStru& );
	void GetSickInfo(UserSickInfo&);
//	wstring GetMedRead(wstring ti_); //סԺ��¼
	void GetMedRecdVector(map<wstring, wstring>& );
	void GetLoginInfo(UserLoginfo& str_);
	void SetUserName_(wstring name_)
	{
		uname = name_;
	}

	virtual wstring GetUserName_()
	{
		return uname;
	}


};

class AdminUser:public CUser
{
public:
	AdminUser();
	AdminUser(AdminUser&);
	AdminUser(CUser&);
	~AdminUser();

	NormalUser cur_nuser;

private:
	wstring name;
	int per;

public:
	void  GetUserLoginInfo(vector<UserLoginfo>& all);
	void  GetSelfLoginInfo(UserLoginfo& u);
	bool  UpdateNorUser(UserInfoStru& stru_);
	bool  UpdateNorLogin(UserLoginfo& stru_);
	bool  UpdateNorSick(UserSickInfo& stru_);
	bool  UpdateUserRecord(UserRecordInfo& stru_);
	bool  DelRecByNT(wstring& name_, wstring& time_);
	bool  DelUserInfo(wstring& uname);
	bool  DelUser(wstring& uname);
	bool  DelUserSick(wstring &uname);
	wstring GetAdName()
	{
		return name;
	}

	int GetAdPer()
	{
		return per;
	}

	inline bool Connect_datebase();

	virtual wstring GetUserName_()
	{
		return name;
	}

};