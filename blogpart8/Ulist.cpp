#include "Ulist.h"
#include "User.h"
#include "SuperUser.h"
#include "Area.h"
#include "Post.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
template <class U> Ulist<U>::Ulist() {

}

template <class U> void Ulist<U>::displayUsers() {
	cout << "Number of users on list: " << list.size() << endl;

	for (int i = 0; i < list.size(); i++) {
		cout << "username: " << list.at(i)->getName() << endl;
	}
}

template <class U> void Ulist<U>::AddUsers(U* NUser) {
	if (find(list.begin(), list.end(), NUser) = list.end()) {

		list.push_back(NUser);
	}
}

template <class U> void Ulist<U>::addtoList(U* item) {
	if (find(list.begin(), list.end(), item) == list.end()) {
		list.push_back(item);
	}
}