#include <iostream>
using std::cout;
using std::string;
using std::endl;

string lookup(string input){
    if(input=="000"){
        cout << "returning 0..";
        return "0";
    }
    if(input=="001"){
        cout << "returning 1..";
        return "1";
    }
    if(input=="010"){
        cout << "returning 2..";
        return "2";
    }
    if(input=="011"){
        cout << "returning 3..";
        return "3";
    }
    if(input=="100"){
        cout << "returning 4..";
        return "4";
    }
    if(input=="101"){
        cout << "returning 5..";
        return "5";
    }
    if(input=="110"){
        cout << "returning 6..";
        return "6";
    }
    if(input=="111"){
        cout << "returning 7..";
        return "7";
    }
    return "error in input";
}

int main(){
    cout << lookup("0001");
    return 0;
}

