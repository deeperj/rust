#pragma once

#include "Session.h"

class Manager; // forward declare Manager class

class AuthMgrGui
{
private:
	Manager* auth;
public:
	void Display(Session session);
};
