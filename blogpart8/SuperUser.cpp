//
// Created by 18604 on 3/3/2020.
//

#include "SuperUser.h"
SuperUser::SuperUser()
{
    this->setUserType(SUPERUSER);
}

SuperUser::SuperUser(string nm, string alias, string pwd) :User(nm, alias, pwd)
{
    this->setUserType(SUPERUSER);
}
