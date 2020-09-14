#include "Details.h"
Details::Details(const Details& d)
{
	UserEmail = d.UserEmail;
	UserPassword = d.UserPassword;
	EmailHash = d.EmailHash;
}

