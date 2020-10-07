#pragma once

#include "Details.h"
#include "Session.h"
#include "AuthMgrGui.h"

class Manager
{
private:
	AuthMgrGui gui;
	Session session;
public:
	void login(Details user);
	void registerUser(Details user);
	void requestReset(Details user);
	void ResetPassword(Details user);
};
