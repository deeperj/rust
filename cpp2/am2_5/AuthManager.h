#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <curses.h>
#include <assert.h>

using namespace std;

enum Session {RegSess
	, RegErrSess
	,LoginSess
	,LoginErrSess
	, ResetSess
	,ResetErrSess
	,UserSess
};

class Details {
private:

public:
	Details() {}
	Details(string un, string pw, string mn) : username(un), password(pw), maidenName(mn) {}
	string username, password, maidenName;
	void reset() { username = "", password = "", maidenName = ""; }
	string getUsername(){return username;}
	string getPassword(){return password;}
	string getMaidenName(){return maidenName;}
};

class AuthManager {
private:
	vector<Details> users;
	void readFile();
	int getUsernameIndex(string username);
public:
	bool error=false;
	string errmsg;
	Session session;
	Details user;
	AuthManager() { readFile(); }
	bool ValidateUsername(string username);
	bool ValidatePassword(string username, string password);
	bool ValidateMaidenName(string username, string maidenName);
	void Register(string username, string password, string maidenName);
	void resetPassword(string username, string maidenName, string newPassword);
	void reset();
	void  Login();
	void  Reg() ;
	void  Reset();
};