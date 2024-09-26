#include <iostream>
#include <iomanip>
#include <vector>
#include <cctype>
#include "Category.h"
#ifndef TODOLIST_H
#define TODOLIST_H

using namespace std;

class TodoList {
private:
	string name;
	vector<Category> categories;
public:
	TodoList(string name);
	~TodoList() {};
	string getName();
	vector<Category>& getCategories();
	void showList();
	void addCategory(Category newCat);
	void deleteCategory(int index);
	void clearList();
};

#endif