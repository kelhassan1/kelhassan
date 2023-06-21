//
// Created by 18604 on 3/3/2020.
//
#include <iostream>

// students - you need to put program header here
using namespace std;

#ifndef GAMESTART_SUPERUSER_H
#define GAMESTART_SUPERUSER_H

#include "User.h"

class SuperUser : public User {
public:
    SuperUser();
    SuperUser(string nm, string alias, string pwd);

    //overload <<
    friend ostream& operator <<(ostream& outputStream, SuperUser& u)
    {
        outputStream << "-----SUPER USER----" << endl;
        outputStream << "Hello " << u.getName() << endl;
        return outputStream;
    };

    void ChangeAlias(string a)
    {
        this->setAlias(a);
    }

};


#endif //GAMESTART_SUPERUSER_H
