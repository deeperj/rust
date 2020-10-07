#include "AuthManager.h"

void AuthManager::Login() {
	if (!ValidateUsername(user.username)) {
		errmsg= "Username not found, please register.\n";
		error=true;
		session = LoginErrSess;
		return;
	}
	else if (!ValidatePassword(user.username, user.password)) {
		errmsg = "Wrong Password.\n";
		error = true;
		session = LoginErrSess;
		return;
	}
	session = UserSess;
}

void AuthManager::Reg() {
	if (ValidateUsername(user.username)) {
		errmsg = "Username already in use \n";
		error = true;
		session = RegErrSess;
		return;
	}
	Register(user.username, user.password, user.maidenName);
	session = UserSess;
}
void AuthManager::Reset() {
	if (!ValidateUsername(user.username)) {
		errmsg = "Username not found\n";
		error = true;
		session = ResetErrSess;
		return;
	}
	else if (!ValidateMaidenName(user.username,user.maidenName)) {
		errmsg = "Wrong Maiden name \n";
		error = true;
		session = ResetErrSess;
		return;
	}
	resetPassword(user.username, user.password, user.maidenName);
	session = UserSess;
}

void AuthManager::readFile() {
	users.clear();
	string row;
	ifstream file;
	file.open("text.txt");
	while (getline(file, row)) {
		if (row != " ") {
			string name, password, maidenName;
			while (row != "") {
				if (name == "") {
					name = row.substr(0, row.find(" "));
					row.erase(0, row.find(" ") + 1);
				}
				else if (password == "") {
					password = row.substr(0, row.find(" "));
					row.erase(0, row.find(" ") + 1);
				}
				else {
					maidenName = row;
					row = "";
				}
			}
			users.push_back(Details(name, password, maidenName));
		}
	}
	file.close();
}

void AuthManager::reset() { 
	user.reset(); 
	error = false;
	errmsg = "";
}

int AuthManager::getUsernameIndex(string username) {
	for (int i = 0; i < users.size(); i++) {
		if (username == users.at(i).getUsername()) {
			return i;
		}
	}/*return -1;*/
}

bool AuthManager::ValidateUsername(string username) {
	for (int i = 0; i < users.size(); i++) {
		if (username == users.at(i).getUsername()) {
			return 1;
		}
	}return false;
}

bool AuthManager::ValidatePassword(string username, string password) {
	int index = getUsernameIndex(username);
	return (password == users.at(index).getPassword());
}

bool AuthManager::ValidateMaidenName(string username, string maidenName) {
	int index = getUsernameIndex(username);
	return (maidenName == users.at(index).getMaidenName());
}

void AuthManager::Register(string username, string password, string maidenName) {
	ofstream file;
	file.open("text.txt", ios::app);
	if(!file){
		error=true;
		session=RegErrSess;
		errmsg="Error opening text.txt";
	}
	file << "\n" + username + " " + password + " " + maidenName;
	file.close();
	readFile();
}
void AuthManager::resetPassword(string username, string maidenName, string newPassword) {
	int index = getUsernameIndex(username);
	string text = "";
	fstream file;
	file.open("text.txt");
	string row;
	while (getline(file, row)) {
		if (row != "") {
			if (text != "") {
				text += "\n";
			}
			if (username != row.substr(0, row.find(" "))) {
				text += row;
			}
			else {
				text += username + " " + newPassword + " " + maidenName;
			}
		}
	}
	file.close();

	ofstream fileWrite;
	fileWrite.open("text.txt", ios::trunc);
	fileWrite << text;
	fileWrite.close();

	readFile();
}