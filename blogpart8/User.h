//
// Created by 18604 on 3/10/2022.
//
#include <iostream>

// students - you need to put program header here
using namespace std;


#ifndef BLOGPART3_USER_H
#define BLOGPART3_USER_H

enum UserTypes { NORMAL, SUPERUSER };

class User {
public:
    User();
    User(string nm, string alias, string pwd);

    // return the Name
    string getName() const;

    // return the Alias
    string getAlias() const;

    // return the Password
    string getPassword() const;

    // return the Alias
    void setAlias(string a);
    virtual void ChangeAlias(string a);

    //
    void setName(string nm);

    // set the Password
    void setPassword(string p);

    //get & set UserType
    int getUserType() const;
    void setUserType(int  uType);

    //overload <<
    friend ostream& operator <<(ostream& outputStream, User& u)
    {
        outputStream << "Hello " << u.getName() << endl;
        return outputStream;
    };


private:
    string Alias; //title
    string Password; //title
    string Name;

    int UserType;
};


#endif //BLOGPART3_USER_H
