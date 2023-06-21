//
// Created by 18604 on 3/10/2022.
//
#include <iostream>
#include <vector>

// students - you need to put program header here
using namespace std;

#include "Post.h"

#ifndef BLOGPART3_AREA_H
#define BLOGPART3_AREA_H

//Area class
class Area {
public:
    ~Area() {
        Posts.clear();
    }

    //overload <<
    friend ostream& operator <<(ostream& outputStream, const Area& area);


    // return the name of the Area
    string getName() const;

    //set the name of the Area
    void setName(string nm);

    // return the description of the Area
    string getDescription() const;

    //set the Description of the Area
    void setDescription(string desc);

    // return the index of the last post
    int getIndxLastPost() const;

    // add post
    int AddPost(Post p);

    // get post
    bool getPost(int i, Post& p) const;

    // delete post
    void deletePost(int i);

    //add post feeling
    void AddPostFeeling(int postId, FeelingsPost fp);
    // get post
    bool EditAPost(int i, Post p);

    bool UniqueNewPost(Post p);

private:
    string Name; //name of Area
    string Description; //name of Area
    vector<Post> Posts;//array of posts
};


#endif //BLOGPART3_AREA_H
