//
// Created by 18604 on 3/11/2022.
//

#include "FeelingsPost.h"
FeelingsPost::FeelingsPost(string a, int f)
{
    feeling = f;
    alias = a;
}

int FeelingsPost::getFeeling() {
    return feeling;
}
string FeelingsPost::getAlias()
{
    return alias;
}


void FeelingsPost::setFeeling(int f)
{
    feeling = f;
}
void FeelingsPost::setAlias(string a) {
    alias = a;
}
