#include "manager.h"

void Details::clear() {
    Email.clear();
    Password.clear();
    PasswordVerify.clear();
    Maiden.clear();
}
Error::Error(ErrorCode e) {
    code = e;
}
ErrorCode Error::getError() {
    return code;
}
string Error::message() {
    switch (code)
    {
    case UserNotFound:
        return "User not found!";
        break;
    case PasswordLengthError:
        return "Minimum Password Length error!";
        break;
    case PasswordError:
        return "Check Password";// meets minimum lengthand password matches verify password!";
        break;
    case ResetError:
        return "Please check the password matches or not a registered user!";
        break;
    default:
        return "Error in manager. Contact developers";
        break;
    }
}
void Status::setStatus(StatusCode s) {
    code = s;
}
StatusCode Status::statusCode() {
    return code;
}
void Status::add(Error e) {
    errors.push_back(e);
}
string Status::status() {
    switch (code)
    {
    case UserSession:
        return "user found!";
        break;
    case LoginErrorSession:
    case RegisterErrorSession:
    case ResetErrorSession:
        return errors[0].message();
        break;
    default:
        return "unknown status!";
        break;
    }
}
Session::Session() {
    Details d1;
    d1.Email = "hello";
    d1.Password = "ok";
    d1.Maiden = "ok";
    validUsers.push_back(d1);
}
Status Session::getStatus() {
    return status;
}
void Session::setStatus(StatusCode s) {
    status.setStatus(s);
}
StatusCode Session::getStatusCode() {
    return status.statusCode();
}
string Session::toString() {
    return status.status();
}
bool Session::ValidateEmail() {
    return false;
};

bool Session::ValidatePassword() {

    if (ValidatePasswordLength()
         && 
        ValidateVerifyPassword()
        ) {
        return true;
    }
    else {
        status.add(Error(PasswordError));
        return false;
    }
};
bool Session::ValidateVerifyPassword() {

    if (user.Password == user.PasswordVerify) {

        return true;
    }
    /*
    start
    input pw, vpw as strings;
    if(pw==vpw) is (yes)
     :return true;
    else (no)
     :return false;
    endif
    stop
    */
    else return false;
}
bool Session::ValidatePasswordLength() {
    if (user.Password.length() < 5)return false;
    return true;
};

bool Session::ValidateMaiden() {
    if (user.Maiden==validUsers[found].Maiden)
        return true;
    status.add(Error(ResetError));
    return false;
};

bool Session::ValidateUser() {
    // cout << "searching for.." << user.Email << user.Password << validUsers.size()<< endl;
    for (int i = 0; i < validUsers.size(); i++) {
        if (user.Email == validUsers[i].Email
            && user.Password == validUsers[i].Password)
        {
            found = i;
            return true;
        }
    }
    status.add(Error(UserNotFound));
    //cout << toString() << endl;
    return false;
}

/*
for a field we can validate the following
1. if in database i.e list of valid users
2. validate if format ok**
3. if field has a value
*/
void Manager::Register() {
    if (session.ValidatePassword()) {
        session.validUsers.push_back(session.user);
        session.setStatus(UserSession);
    }
    else {
        session.setStatus(RegisterErrorSession);
    }
}
void Manager::RequestReset() {
    if (session.ValidateUser()
        && session.ValidatePassword()
        && session.ValidateMaiden()
        ) {
        session.setStatus(UserSession);
        session.user = session.validUsers[session.found];
    }else{
        session.setStatus(ResetErrorSession);
    }
}
void Manager::Login() {
    if (session.ValidateUser()) {
        session.setStatus(UserSession);
        session.user = session.validUsers[session.found];
    }
    else {
        session.setStatus(LoginErrorSession);
    }
}
