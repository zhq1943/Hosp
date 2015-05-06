#include <iostream>
#include "CDatabaseCon.h"
using namespace std;
wstring database_ = L".//newe.mdb";

class CUser
{
public:
	CUser();
	CUser(const CUser&);
	virtual ~CUser();

private:
	wstring user_name;

	wstring passworld;

	int per;

public:
	bool CheckUser(wstring name, wstring password);

};

class NormalUser:public CUser
{
public:
	NormalUser();
	NormalUser(const NormalUser&);
	~NormalUser();
private:


};