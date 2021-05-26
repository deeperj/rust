#include "Header.h"
// Checking Login Details for to permit the user to his account. 
bool SessionManager::CheckLoginDetails(string username, string password){
  for(int a=0; a < 10; a++){
    if (Data.Usernames[a] == username){
      if (Data.password[a] == password){
        return true;
      }
    }
  }
  return false;  
}
// Checking the username from the database.
bool SessionManager::CheckSignupDetails(string username){
  for(int a=0; a < 10; a++){
    if (Data.Usernames[a] == username){
        return false;
    }
  }
  return true;  
}
//Saving Login Details to give the accout access to tne user.
void SessionManager::SaveAccount(string username, string password, string mother){
  for(int a=0; a < 10; a++){
    if (Data.Usernames[a].empty() == true){
        Data.Usernames[a] = username;
        Data.password[a] = password;
        Data.maidens_name[a] = mother;
        break;
    }
  }
}
// CheckResetDetails to upgrade password.
bool SessionManager::CheckResetDetails(string username, string newPassword, string mother){
  for(int a=0; a < 10; a++){
    if (Data.Usernames[a] == username){
        if(Data.maidens_name[a] == mother){
          UpdatePassword(a, newPassword);
          return true;
        }
    }
  } 
       return false;
}
// Upgarding password in the ResetPage.
void SessionManager::UpdatePassword(int Index, string newPassword){
    Data.password[Index] = newPassword;
}