//
// Created by 18604 on 3/10/2022.
//

#include "Post.h"

Post::Post() {
    this->Title = "";
    this->Text = "";
    this->User = "";
}

Post::Post(string u, string t, string txt) {
    this->Title = t;
    this->Text = txt;
    this->User = u;
}

// return the Title
string Post::getTitle() const {
    return this->Title;
};

// return the Text
string Post::getText() const {
    return this->Text;
};

// return the User
string Post::getUser() const {
    return this->User;
};

// return the Title
void Post::setTitle(string t) {
    this->Title = t;
};

// return the Text
void Post::setText(string txt) {
    this->Text = txt;
};

// set the User
void Post::setUser(string u) {
    this->User = u;
};

void Post::AddPostFeeling(FeelingsPost fp) {
    this->PostFeelings.push_back(fp);

}

string Post::countPostFeeling() {
    if (PostFeelings.size() == 0)
        return "There are no posted responses to this.";

    int numLove = 0;
    int numLike = 0;
    int numDislike = 0;
    int numHate = 0;
    for (int i = 0; i < PostFeelings.size(); i++) {
        switch (PostFeelings[i].getFeeling()) {
        case LOVE:
            numLove++;
            break;
        case LIKE:
            numLike++;
            break;
        case DISLIKE:
            numDislike++;
            break;
        case HATE:
            numHate++;
            break;
        }
    }

    string result;
    result = "Num Love    = " + to_string(numLove) + "\n";
    result += "Num Like    = " + to_string(numLike) + "\n";
    result += "Num Dislike = " + to_string(numDislike) + "\n";
    result += "Num Hate    = " + to_string(numHate) + "\n";
    for (int i = 0; i < PostFeelings.size(); i++) {
        result += PostFeelings[i].getAlias() + " ";
        if (PostFeelings[i].getFeeling() == 0) {
            result += " Love\n ";
        }
        else if (PostFeelings[i].getFeeling() == 1) {
            result += " Likes\n ";
        }
        else if (PostFeelings[i].getFeeling() == 2) {
            result += " Dislikes\n ";
        }
        else if (PostFeelings[i].getFeeling() == 3) {
            result += " Hates\n ";
        }
    }
    return result;
}

//overload <<
ostream& operator<<(ostream& outputStream, Post p) {
    outputStream << "Title:" << p.getTitle() << endl;
    outputStream << "By:" << p.getUser() << endl;
    outputStream << "Text:" << p.getText() << endl;
    outputStream << p.countPostFeeling() << endl;
    return outputStream;
}

//overload ==
bool Post::operator==(const Post& otherPost) {
    return (this->Title == otherPost.Title);
}

//
string Post::OutputPostFeelings()
{
    string out;
    int numFeelings = PostFeelings.size();
    out = to_string(numFeelings) + "\n";
    for (int i = 0; i < numFeelings; i++) {
        out += PostFeelings[i].getAlias() + "\n";
        out += to_string(PostFeelings[i].getFeeling()) + "\n";
    }
    return out;
}

