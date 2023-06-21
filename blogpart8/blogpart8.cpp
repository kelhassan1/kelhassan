#include <iostream>
#include <vector>
#include <fstream>
#include <string>


#include "Post.h"
#include "Area.h"
#include "User.h"
#include "SuperUser.h"
#include "FeelingsPost.h"
#include "Ulist.h"
#include "Ulist.cpp"

// students - you need to put program header here
using namespace std;

////////////////////////////////////////////////////
// sets up Areas
void initAreas(vector<Area>* Areas);

//display menu
void displayMenu();

//User selects an action
void promptAction(string& strCh);

//implement Action
void implementAction(vector<Area>* areas, string strCh, User* u1, bool bSuperUser, Ulist<User> list);

void DisplayBlogAreas(vector<Area> areas);

void DisplayPostsABlog(Area a);

void AddaPost(Area& a, string strAlias);

void DisplayAPost(int postId, Post p);

void EditaPost(int PostId, Area& a, string strAlias);

//get a valid blog area id
int getValidBlogArea(int NumAreas);

//get a valid post id
int getValidPostId(Area a);

//get a valid post response
int getValidPostResponse();

//get a valid string max chars
string getValidString(int maxChars);

//log in user
template<class T>
User* Login(vector<T> users);

// Save data to file
void SaveData(vector<Area> areas);

//load data from file
void LoadData(vector<Area>* areas);

int main() {
  
    vector<User*> users;
    Ulist<User> list;

    User* u = new User("Works", "Kwrky", "test123");
    list.addtoList(u);
    users.push_back(u);
    u = new User("Dude", "Dude", "test456");
    users.push_back(u);
    list.addtoList(u);
    u = new User("Tim", "Slim", "test789");
    users.push_back(u);
    list.addtoList(u);
    u = new User("Catherine", "Cat", "test987");
    users.push_back(u);
    list.addtoList(u);
    u = new User("Theo", "EI", "test654");
    users.push_back(u);
    list.addtoList(u);
    SuperUser* su = new SuperUser("Michael", "Mike", "test321");
    users.push_back(su);
    list.addtoList(su);

    //log in
    User* u1 = Login(users);

    vector<Area> areas;
    LoadData(&areas);
    //initAreas(&areas);

    //welcome
    bool bSuperUser = false;
    if (u1->getUserType() == SUPERUSER) {
        cout << *((SuperUser*)(u1));
        bSuperUser = true;
    }
    else
        cout << *u1;
    cout << "Welcome to my Blog " << endl;

    string UserAction;
    do {
        promptAction(UserAction);
        implementAction(&areas, UserAction, u1, bSuperUser, list);
    } while ((UserAction != "Q") && (UserAction != "q"));
    //continue until user decides to quit

    SaveData(areas);

    return 0;
}

////////
    template <class T>
User* Login(vector<T> users) {
    User* u = 0;
    string name;
    string password;
    bool bFound = false;
    do {
        cout << "Login:" << endl;
        cout << "Name:";
        name = getValidString(10);
        cout << endl;
        cout << "Password:";
        password = getValidString(20);

        bFound = false;
        int i = 0;
        while (!bFound && i < users.size()) {
            if ((name == users[i]->getName()) && (password == users[i]->getPassword())) {
                u = users[i];
                bFound = true;
            }
            i++;
        }

    } while (!bFound);
    return u;
}


// sets up areas
void initAreas(vector<Area>* areas) {
    //init Com Sci
    Area a1, a2, a3, a4, a5;
    a1.setName("Com Sci");
    a1.setDescription("This blog is where people post about computer science.");

    //add a post to the Com Sci area
    Post p{ "I love programming",
           "Programming is so much fun.",
           "Tom" };
    a1.AddPost(p);

    //add another post to the Com Sci area
    Post p2;
    p2.setTitle("C++ versus Python");
    p2.setText("I like C++ more than Python.");
    p2.setUser("Sally");
    a1.AddPost(p2);

    areas->push_back(a1);

    //init Current Events
    a2.setName("Current Events");
    a2.setDescription("This blog is where people post current events.");

    //add a post to the Current Events area
    Post p3{ "Picnic Saturday",
            "Join us at the park for a picnic on Saturday",
            "Sue" };
    a2.AddPost(p3);
    areas->push_back(a2);


    //init Movies
    a3.setName("Movies");
    a3.setDescription("This blog is where people post things about movies.");
    //add a post to the Movies area
    p = { "My Fav Movie",
         "Star Wars",
         "Billy" };
    a3.AddPost(p);
    //add a post to the Movies area
    p = { "Movie I despise",
         "The clock work orange",
         "Jean" };
    a3.AddPost(p);
    areas->push_back(a3);

    //init Food
    a4.setName("Food");
    a4.setDescription("This blog is where people post things about food.");
    //add a post to the Food area
    p = { "My fav Pizza",
         "I love Pizza with extra cheese and onions",
         "Bailey" };
    a4.AddPost(p);
    //add a post to the Food area
    p = { "Icecream",
         "I love coffe icecream with chocolate jimies",
         "Joe" };
    a4.AddPost(p);
    areas->push_back(a4);

    //init Vacation
    a5.setName("Vacation");
    a5.setDescription("This blog is where people post things about vacations.");
    //add a post to the Vacation area
    p = { "Best place to Vacation",
         "Baniff Canada",
         "Kyle" };
    a5.AddPost(p);
    //add a post to the Vacation area
    p = { "Worst Vacation",
         "Stayed at home",
         "Mary Jo" };
    a5.AddPost(p);
    areas->push_back(a5);

}

//display menu
void displayMenu() {
    cout << "Please select from the following options..." << endl;
    cout << " A  - Display Blog areas" << endl;
    cout << " B  - Display all posts for a blog" << endl;
    cout << " C  - Add a post to a blog" << endl;
    cout << " D  - Display a post for a blog" << endl;
    cout << " E  - Edit a post for a blog" << endl;
    cout << " F  - Delete a post for a blog" << endl;
    cout << " G  - Love/Like/Dislike/Hate a post" << endl;
    cout << " H  - Delete an area" << endl;
    cout << " I  - Change your alias" << endl;
    cout << " Z  - See all usernames" << endl;
    cout << " Q  - Quit" << endl;

}

//User Action
void promptAction(string& strCh) {
    displayMenu();

    //prompt user for choice
    cout << "What would you like to do?" << endl;
    cin >> strCh;
}

//implement Users Action
void implementAction(vector<Area>* areas, string strCh, User* u1, bool bSuperUser, Ulist<User> list) {

    if ((strCh == "A") || (strCh == "a")) {
        DisplayBlogAreas(*areas);
    }
    else if ((strCh == "B") || (strCh == "b")) {
        cout << "Display all posts for a blog..." << endl;
        int blogId = getValidBlogArea(areas->size());
        DisplayPostsABlog((*areas)[blogId]);
    }
    else if ((strCh == "C") || (strCh == "c")) {
        cout << "Add a post to a blog..." << endl;
        int blogId = getValidBlogArea(areas->size());
        AddaPost((*areas)[blogId], u1->getAlias());
    }
    else if ((strCh == "D") || (strCh == "d")) {
        cout << "Display a post for a blog..." << endl;
        int blogId = getValidBlogArea(areas->size());
        Area area = (*areas)[blogId];
        int postId = getValidPostId(area);
        Post p;
        bool found = (*areas)[blogId].getPost(postId, p);
        if (found) {
            DisplayAPost(postId, p);
        }

    }
    else if ((strCh == "E") || (strCh == "e")) {
        cout << "Edit a post for a blog..." << endl;
        int blogId = getValidBlogArea(areas->size());
        int postId = getValidPostId((*areas)[blogId]);
        Post p;
        bool found = (*areas)[blogId].getPost(postId, p);
        if (found) {
            DisplayAPost(postId, p);
            EditaPost(postId, (*areas)[blogId], u1->getAlias());
        }
    }
    else if ((strCh == "F") || (strCh == "f")) {
        cout << "Delete a post for a blog..." << endl;
        int blogId = getValidBlogArea(areas->size());
        int postId = getValidPostId((*areas)[blogId]);
        (*areas)[blogId].deletePost(postId);
        cout << "Post deleted" << endl;
    }
    else if ((strCh == "G") || (strCh == "g")) {
        cout << "Love/Like/Dislike/Hate a post....." << endl;
        int blogId = getValidBlogArea(areas->size());
        int postId = getValidPostId((*areas)[blogId]);
        int resp = getValidPostResponse();
        cin.ignore();
        FeelingsPost fp(u1->getAlias(), resp);
        (*areas)[blogId].AddPostFeeling(postId, fp);
        cout << "Response to Post saved" << endl;
    }
    else if ((strCh == "H") || (strCh == "h")) {
        if (!bSuperUser) {
            cout << "You are not a super user and do not have permissions to perform this action." << endl;
        }
        else {
            cout << "Delete an area....." << endl;
            int blogId = getValidBlogArea(areas->size());
            areas->erase(areas->begin() + blogId);
        }
    }
    else if ((strCh == "I") || (strCh == "i")) {
        if (!bSuperUser) {
            cout << "You are not a super user and do not have permissions to perform this action." << endl;
        }
        else {
            cout << "Change your alias....." << endl;
            cout << "Please enter in your new alias..." << endl;
            string alias = getValidString(20);
            ((SuperUser*)u1)->ChangeAlias(alias);

        }
    }
    else if ((strCh == "Z") || (strCh == "z")) {
        if (!bSuperUser) {
            cout << "You are not a super user and do not have permissions to perform this action." << endl;
        }
        else {
            cout << "all usernames" << endl;
            list.displayUsers();
        }
    }
    else if ((strCh == "Q") || (strCh == "q")) {
        //user has selected to quit
        cout << "Bye..." << endl;
    }
    else {
        //user has selected an invalid option
        cout << strCh << " is not a valid option." << endl;
    }
}

////////////////////////////
void DisplayBlogAreas(vector<Area> areas) {
    cout << "Display Blog areas..." << endl;
    //user has selected to display blog areas
    for (int i = 0; i < areas.size(); i++) {
        cout << "Area Index:" << i << endl;
        cout << areas[i];
        cout << "******************" << endl;
    }

}

//////////////////
void DisplayPostsABlog(Area a) {
    cout << "Posts for " << a.getName() << endl;

    //user has selected to display blog areas
    for (int i = 0; i <= a.getIndxLastPost(); i++) {
        Post p;
        bool found = a.getPost(i, p);
        if (found) {
            cout << "Post Index:" << i << endl;
            cout << p;
            cout << "******************" << endl;
        }
    }

}

/////////////////
void AddaPost(Area& a, string strAlias) {
    cin.ignore();

    Post p;
    string Title;
    do {
        cout << "Please enter in the title..." << endl;
        Title = getValidString(20);
        p.setTitle(Title);
    } while (!a.UniqueNewPost(p));


    cout << "Please enter in the text..." << endl;
    string Text = getValidString(500);

    p.setText(Text);
    p.setUser(strAlias);

    if (a.AddPost(p))
        cout << "Post successfully added" << endl;
    else
        cout << "Error adding Post " << endl;

}

void EditaPost(int PostId, Area& a, string strAlias) {
    cin.ignore();
    Post p;
    string Title;
    do {
        cout << "Please enter in the title..." << endl;
        Title = getValidString(20);
        p.setTitle(Title);
    } while (!a.UniqueNewPost(p));

    cout << "Please enter in the text..." << endl;
    string Text = getValidString(500);

    p.setText(Text);
    p.setUser(strAlias);


    if (a.EditAPost(PostId, p)) {
        cout << "Post Editted" << endl;
    }


}

/////////////////
void DisplayAPost(int postId, Post p) {
    cout << "Post Index:" << postId << endl;
    cout << p << endl;
    cout << "******************" << endl;
}


//////////////
int getValidBlogArea(int NUM_AREAS) {
    int area;
    cout << "Please enter in a Blog Area Index" << endl;
    cin >> area;
    while ((area < 0) || (area >= NUM_AREAS)) {
        cout << "Please enter in a Blog Area Index" << endl;
        cin >> area;
    }
    return area;
}

///////////////
int getValidPostId(Area area) {
    int PostId;
    do {
        cout << "Please enter in a valid post id for area: " << area.getName() << endl;
        cin >> PostId;
    } while ((PostId < 0) || (PostId > area.getIndxLastPost()));
    return PostId;
}


int getValidPostResponse() {
    int resp;
    cout << "Select " << endl;
    cout << " 1 = Love" << endl;
    cout << " 2 = Like" << endl;
    cout << " 3 = Dislike" << endl;
    cout << " 4 = Hate" << endl;
    cin >> resp;
    while ((resp < 1) || (resp > 4)) {
        cout << "Select " << endl;
        cout << " 1 = Love" << endl;
        cout << " 2 = Like" << endl;
        cout << " 3 = Dislike" << endl;
        cout << " 4 = Hate" << endl;
        cin >> resp;

    }
    return resp - 1;
}


////////////////////////
/////////////////////////

///////////////////////////////////////
const std::string WHITESPACE = " \n\r\t\f\v";

///////////////////////////
string ltrim(const std::string& s) {
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

string rtrim(const std::string& s) {
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const std::string& s) {
    return rtrim(ltrim(s));
}

string getValidString(int maxChars) {
    string text;
    do {
        cout << "Please enter in a string with at least 1 character and at most " << maxChars << " characters." << endl;
        getline(cin, text);
        text = trim(text);
    } while ((text.length() == 0) || (text.length() > maxChars));
    return text;
}

void SaveData(vector<Area> areas) {
    ofstream fout;
    fout.open("BlogData.txt");
    if (fout.fail()) {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    //cout << "Output file opened.\n";
    for (int i = 0; i < areas.size(); i++) {
        fout << areas[i].getName() << endl;
        fout << areas[i].getDescription() << endl;
        fout << areas[i].getIndxLastPost() << endl;
        for (int j = 0; j < areas[i].getIndxLastPost(); j++) {
            Post p;
            bool found = areas[i].getPost(j, p);
            if (found) {
                fout << p.getTitle() << endl;
                fout << p.getUser() << endl;
                fout << p.getText() << endl;
                fout << p.OutputPostFeelings();
            }
        }
    }
    //close file
    fout.close();
}

void LoadData(vector<Area>* areas) {
    cin.ignore();
    ifstream fin;
    fin.open("BlogData.txt");
    if (fin.fail()) {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    //cout << "Output file opened.\n";
    string strName;
    while (getline(fin, strName)) {
        string strDescription;
        getline(fin, strDescription);
        Area a;
        a.setName(strName);
        a.setDescription(strDescription);
        //cout<<strName<<endl;
        //cout<<strDescription<<endl;
        int NumPosts;
        fin >> NumPosts;
        //cout<<NumPosts<<endl;
        fin.ignore();
        for (int i = 0; i < NumPosts; i++) {
            string strTitle, strUser, strText;
            getline(fin, strTitle);
            getline(fin, strUser);
            getline(fin, strText);
            Post p{ strTitle, strUser, strText };
            a.AddPost(p);

            int NumPostsFeelings;
            fin >> NumPostsFeelings;
            //cout<<NumPosts<<endl;
            fin.ignore();
            for (int j = 0; j < NumPostsFeelings; j++) {
                string strAlias;
                int Feeling;
                getline(fin, strAlias);
                fin >> Feeling;
                //cout<<NumPosts<<endl;
                fin.ignore();
                FeelingsPost fp(strAlias, Feeling);
                a.AddPostFeeling(i, fp);
            }
        }
        areas->push_back(a);
    }
    //close file
    fin.close();

}

