#include "authmgr.h"

void Details::clear(){
    Email.clear();
    Password.clear();
    PassordVerify.clear();
    EmailHash.clear();
}
Error::Error(ErrorCode e){
    code=e;
}
ErrorCode Error::getError(){
    return code;
}
string Error::message(){
    switch (code)
    {
    case UserNotFound:
        return "User not found!";
        break;
    case PasswordLengthError:
        return "Minimum Password Length error!";
        break;
    
    default:
        break;
    }
}
void Status::setStatus(StatusCode s){
    code=s;
}
StatusCode Status::statusCode(){
    return code;
}
void Status::add(Error e){
    errors.push_back(e);
}
string Status::status(){
    switch (code)
    {
    case UserSession:
        return "user found!";
        break;
    case LoginErrorSession:
    case RegisterErrorSession:
        return errors[0].message();
        break;
    
    default:
        break;
    }
}
Session::Session(){
    Details d1;
    d1.Email="hello@manager.auth";
    d1.Password="world";
    validUsers.push_back(d1);
}
Status Session::getStatus(){
    return status;
}
void Session::setStatus(StatusCode s){
    status.setStatus(s);
}
StatusCode Session::getStatusCode(){
    return status.statusCode();
}
string Session::toString(){
    return status.status();
}
void Session::ValidateEmail(){};
void Session::ValidatePassword(){
    if(ValidatePasswordLength()
    // && ValidateVerifyPassword()
    ){
        setStatus(UserSession);
    }else{
        status.add(Error(PasswordLengthError));
    }
};
bool Session::ValidatePasswordLength(){
    if(user.Password.length()<5)return false;
    return true;
};
void Session::ValidateUser(){
    // cout << "searching for.." << user.Email << user.Password << validUsers.size()<< endl;
    for(int i=0;i<validUsers.size();i++){
        if(user.Email==validUsers[i].Email
            && user.Password==validUsers[i].Password)
        {
            user=validUsers[i];
            status.setStatus(UserSession);
            return;
        }
    }status.add(Error(UserNotFound));
    setStatus(LoginErrorSession);
    cout << toString() << endl;
}

/*
for a field we can validate the following
1. if in database i.e list of valid users
2. validate if format ok**
3. if field has a value 
*/
void Manager::Register(){}
void Manager::Login(){
    session.ValidateUser();
}
