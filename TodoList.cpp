#include <iostream>
#include <iomanip>
#include "TodoList.h"

using namespace std;

TodoList::TodoList(string name) :
	name(name)
{}

string TodoList::getName() {
	return name;
}

void TodoList::showList() {
	int num = 1;
	cout << "-------------------------" << endl << endl;
	cout << name << endl << endl;
	for (auto i : list) {
		if (i.first != "U") {
			cout << i.first << ":" << endl;
		}
		cout << i.first << ":" << endl;
		for (Task t : i.second) {
			cout << num << ". " << t.getDesc() << " | " << t.getDeadline() << endl;
			num++;
		}
		cout << endl;
	}
	cout << "-------------------------" << endl;
}

void TodoList::addTask(Task newTask) {
	if (list.empty() || list.find(newTask.getCategory()) == list.end()) {
		vector<Task> newCat;
		newCat.push_back(newTask);
		list[newTask.getCategory()] = newCat;
	}
	else {
		list[newTask.getCategory()].push_back(newTask);
	}

	cout << "Successfully added task to todo list." << endl;

}

void TodoList::newCategory(string category) {
	if (list.find(category) == list.end()) {
		vector<Task> newCat;
		list[category] = newCat;

		cout << "Successfully added new category to todo list." << endl;
	}
	else {
		cout << "ERROR: Category already exists." << endl;
	}
}

void TodoList::deleteCategory(string category) {
	if (list.find(category) == list.end()) {
		cout << "Category does not exist." << endl;
	}
	else {
		list.erase(category);
	}
}