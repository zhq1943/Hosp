#pragma once

#import "C:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "adoEOF")
#include <iostream>
#include <string>
#define  UString std::wstring
#define  EmpStr  L""

class CDatabaseCon
{
public:
	CDatabaseCon();
	virtual ~CDatabaseCon();
public:
	bool Connect_(int ver, UString& datapos, UString& username, UString& password);
	bool Close_();
	UString GetConnectStr(int ver, UString& datapos, UString& username, UString& password);
    bool ExecuteSql(UString& sql);
public:
	UString GetValueStr(UString& name);
	int         GetValueInt(UString& name);
	float       GetValueFlo(UString& name);
	bool        NextRecord();
	bool        Eof();
	bool        GoFirst();
	bool        SetValueStr(UString& key, UString& val);
	bool        SetValueInt(UString& key, int i);
	bool        NewRecord();
	bool        UpdateOk();
	bool        DelCurrentRec();

protected:
	_RecordsetPtr m_RecSet;
	_ConnectionPtr m_Connptr;
	bool iniole;

};

class HelpFun
{
public:
	static UString FormattoUStr( const char* str,... );

};
