#pragma once
#include <iostream>
#include "CDatabaseCon.h"
using namespace std;
extern wstring database_;

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

};

class NormalUser:public CUser
{
public:
	NormalUser();
	NormalUser(const NormalUser&);
	~NormalUser();
private:


};