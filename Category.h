#include <iostream>
#include <iomanip>
#include <vector>
#include "Task.h"
#ifndef CATEGORY_H
#define CATEGORY_H

class Category {
private:
	string name;
	vector<Task> tasks;
public:
	Category(const string& name);
	Category(const string& name, Task task);
	~Category() {};
	void addTask(Task task);
	void editCategory(string newName);
	void showTasks();
};

#endif