#include "Category.h"

using namespace std;

Category::Category(const string& name) :
	name(name)
{
	size = 0;
}

Category::Category(const string& name, Task task) :
	name(name)
{
	tasks.push_back(task);
	size = 1;
}

string Category::getName() {
	return name;
}

void Category::addTask(Task task) {
	tasks.push_back(task);
	size++;
}

void Category::editCategory(string newName) {
	name = newName;
}

void Category::showTasks() {
	cout << name << ": " << endl;
	for (int i = 0; i < size; i++) {
		cout << " " << i+1 << ". " << tasks[i].getDesc() << " | " << tasks[i].getDeadline() << endl;
	}
	cout << endl;
}

