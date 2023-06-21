//
// Created by 18604 on 3/10/2022.
//

#include <iostream>
#include <vector>
#include <string>
#include "FeelingsPost.h"

// students - you need to put program header here
using namespace std;

#ifndef BLOGPART3_POST_H
#define BLOGPART3_POST_H
//////////////////////////////////////////////////////
//structure for post
class Post {
public:


    Post();
    Post(string u, string t, string txt);
    ~Post() {
        PostFeelings.clear();
    }

    struct reaction {
        string reactor;
        int reactionNum;
    };
    // return the Title
    string getTitle() const;

    // return the Text
    string getText() const;

    // return the User
    string getUser() const;

    // return the Title
    void setTitle(string t);

    // return the Text
    void setText(string txt);

    // set the User
    void setUser(string u);

    //overload <<
    friend ostream& operator <<(ostream& outputStream, Post p);

    //overload ==
    bool operator ==(const Post& otherPost);

    // add post Feeling
    void AddPostFeeling(FeelingsPost fp);
    // count post Feeling
    string countPostFeeling();

    string outReact();
    //
    string OutputPostFeelings();
   
private:
    string Title; //title
    string Text; //title
    string User;

    vector<FeelingsPost> PostFeelings;//post feelings
   
};

#endif //BLOGPART3_POST_H
