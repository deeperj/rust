#ifndef MGR_H
#define MGR_H

#include <string>
#include <iostream>
#include <vector>
#include <assert.h>
#include "curses.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Details
{
public:
    string PasswordVerify;
    string Email;
    string Password;
    string Maiden;
    void clear();
};

enum ErrorCode { 
    UserNotFound
    , InvalidEmail
    , PasswordLengthError
    , PasswordError
    , ResetError
};

enum StatusCode {
    UserSession
    , LoginSession
    , LoginErrorSession
    , RegisterErrorSession
    , RegisterSession
    , ForgotPasswordSession
    , ResetErrorSession
};

class Error {
    ErrorCode code;
public:
    Error(ErrorCode);
    string message();
    void setError(ErrorCode);
    ErrorCode getError();
};

class Status {
    StatusCode code;
public:
    vector<Error> errors;
    void add(Error);
    string status();
    StatusCode statusCode();
    void setStatus(StatusCode);
};

class Utility
{
    void setHash(Details user) {};
    void sendEmail(Details user) {};
};
class Session
{
private:
    Status status;
    bool ValidatePasswordLength();
    bool ValidateVerifyPassword();

public:
    friend class Test;
    Details user;
    int found;
    vector<Details> validUsers;
    Session();
    Status getStatus();
    void setStatus(StatusCode status);
    StatusCode getStatusCode();
    string toString();
    bool ValidateEmail();
    bool ValidatePassword();
    bool ValidateUser();
    bool ValidateMaiden();
};

class Manager
{
protected:
    Session session;
public:
    friend class Test;
    void Login();
    void Register();
    void RequestReset();
    void ResetPassword();
};

#endif

