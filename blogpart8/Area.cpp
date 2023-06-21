//
// Created by 18604 on 3/10/2022.
//

#include "Area.h"

// return the name of the Area
string Area::getName() const {
    return this->Name;
};

//set the name of the Area
void Area::setName(string nm) {
    this->Name = nm;
};

// return the description of the Area
string Area::getDescription() const {
    return this->Description;
};

//set the Description of the Area
void Area::setDescription(string desc) {
    this->Description = desc;
};

// return the index of the last post
int Area::getIndxLastPost() const {
    return this->Posts.size();
};

// get post
bool Area::getPost(int i, Post& p) const {
    if (i < this->Posts.size()) {
        p = this->Posts[i];
        return true;
    }
    else { return false; }
}

// get post
bool Area::EditAPost(int i, Post p) {
    if (i < this->Posts.size()) {
        this->Posts[i].setUser(p.getUser());
        this->Posts[i].setTitle(p.getTitle());
        this->Posts[i].setText(p.getText());
        return true;
    }
    else { return false; }
}

bool Area::UniqueNewPost(Post p) {
    for (int i = 0; i < this->Posts.size(); i++) {
        if (this->Posts[i] == p) {
            cout << "Another post in this blog has an identical title.." << endl;
            cout << "Please create a new unique title.." << endl;
            return false;
        }
    }
    return true;
}

// add post
int Area::AddPost(Post p) {
    this->Posts.push_back(p);
    return 1;
}




void Area::deletePost(int i)
{
    Posts.erase(Posts.begin() + i);
}

void Area::AddPostFeeling(int postId, FeelingsPost fp)
{
    if (postId < this->Posts.size())
        this->Posts[postId].AddPostFeeling(fp);
}


//overload <<
ostream& operator <<(ostream& outputStream, const Area& area)
{
    outputStream << "Area Name:" << area.Name << endl;
    outputStream << "Description:" << area.Description << endl;
    return outputStream;
}
