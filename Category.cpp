#include "Category.h"

using namespace std;

Category::Category(const string& name) :
	name(name)
{}

Category::Category(const string& name, Task task) :
	name(name)
{
	tasks.push_back(task);
}

void Category::addTask(Task task) {
	tasks.push_back(task);
}

void Category::editCategory(string newName) {
	name = newName;
}

void Category::showTasks() {
	cout << name << ": " << endl;
	for (int i = 1; i <= tasks.size(); i++) {
		cout << " " << i << ". " << tasks[i].getDesc() << " | " << tasks[i].getDeadline() << endl;
	}
	cout << endl;
}

