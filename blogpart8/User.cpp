//
// Created by 18604 on 3/10/2022.
//

#include "User.h"

User::User() {
    Name = "";
    Alias = "";
    Password = "";
    UserType = NORMAL;

}

User::User(string nm, string alias, string pwd) {
    Name = nm;
    Alias = alias;
    Password = pwd;
    UserType = NORMAL;
}

// return the Name
string User::getName() const {
    return Name;
}

// return the Alias
string User::getAlias() const {
    return Alias;
}

// return the Password
string User::getPassword() const {
    return Password;
}

// return the Alias
void User::setAlias(string a) {
    Alias = a;
}

void User::ChangeAlias(string a)
{

}


//
void User::setName(string nm) {
    Name = nm;

}

// set the Password
void User::setPassword(string p) {
    Password = p;
}

//////////////////////////////
//get & set user type
int User::getUserType() const
{
    return this->UserType;
}
void User::setUserType(int  uType)
{
    this->UserType = uType;
}

