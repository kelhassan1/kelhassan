#pragma once
#include <vector>
#include "Area.h"
#include "Post.h"
#include "SuperUser.h"
#ifndef ULIST_CLASS_H
#define ULIST_CLASS_H
template <class U> class Ulist
{
public:
	Ulist();
	// add user to list
	void AddUsers(U* NUser);
	// display the users in the list
	void displayUsers();

	void addtoList(U* item);

private:
	vector<U*> list;
};

#endif // !ULIST_CLASS_H


