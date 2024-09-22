#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include "Task.h"
#ifndef TODOLIST_H
#define TODOLIST_H

using namespace std;

class TodoList {
private:
	map<string, vector<Task>> list;
	vector<Task> completed;
	set<string> categories;
	string name;
public:
	TodoList(string name);
	~TodoList() {};
	string getName();
	void showList();
	void addTask(Task newTask);
	void newCategory(string category);
	void deleteCategory(string category);
};

#endif