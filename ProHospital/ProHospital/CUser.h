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
	wstring password;
	wstring lasttime;
};

struct UserInfoStru
{
	wstring name;
	wstring sex;
	wstring birthday;
	wstring birthplace;
	wstring warkplace;
	wstring liveplace;
	wstring marrys;
	wstring uname; //id
};

struct UserSickInfo
{
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
	wstring medread;
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

	wstring GetUserName_()
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
	
	wstring sex;
	wstring birthday;
	wstring birthplace;
	wstring warkplace;
	wstring liveplace;
	wstring marrys;

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
	wstring nsick;
	wstring incheck;

	wstring outcheck;
	wstring medread;

	map<wstring, wstring> hosrecord;

	

public:
	virtual bool InitUserInfo();
	virtual bool GetUserInfo(UserInfoStru& );
	void GetSickInfo(UserSickInfo&);
//	wstring GetMedRead(wstring ti_); //×¡Ôº¼ÇÂ¼
	void GetMedRecdVector(map<wstring, wstring>& );
};

class AdminUser:public CUser
{
public:
	AdminUser();
	AdminUser(const AdminUser&);
	AdminUser(CUser&);
	~AdminUser();

	NormalUser cur_nuser;

private:
	wstring name;
	int per;

public:
	void  GetUserLoginInfo(vector<UserLoginfo>& all);

};