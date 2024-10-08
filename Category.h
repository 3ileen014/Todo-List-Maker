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
	int size;
public:
	Category(const string& name);
	Category(const string& name, Task task);
	~Category() {};
	string getName();
	void addTask(Task task);
	void deleteTask(int index);
	void editCategory(string newName);
	void showTasks();
	vector<Task>& getTasks();
};

#endif