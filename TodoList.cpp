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
	if (list.empty()) {
		cout << "No categories/tasks have been added yet." << endl << endl;
	}
	else {
		cout << "-------------------------" << endl << endl;
		cout << name << endl << endl;
		for (auto i : list) {
			cout << i.first << ":" << endl;
			for (Task t : i.second) {
				cout << "- " << t.getDesc() << " | " << t.getDeadline() << endl;
			}
		}
		cout << endl << "-------------------------" << endl;
	}
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
}

