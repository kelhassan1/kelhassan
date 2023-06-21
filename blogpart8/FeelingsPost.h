//
// Created by 18604 on 3/11/2022.
//
#include <iostream>

// students - you need to put program header here
using namespace std;


#ifndef BLOGPART3_FELLINGSPOST_H
#define BLOGPART3_FELLINGSPOST_H

enum FEELINGS { LOVE, LIKE, DISLIKE, HATE };

class FeelingsPost {
public:
    FeelingsPost(string a, int f);

    int getFeeling();
    string getAlias();

    void setFeeling(int f);
    void setAlias(string a);
private:
    int feeling;
    string alias;
};


#endif //BLOGPART3_FELLINGSPOST_H
