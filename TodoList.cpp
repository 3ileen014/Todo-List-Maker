#include "TodoList.h"
#include <algorithm>
#include <string>

using namespace std;

TodoList::TodoList(string name) {
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	this->name = name;
}

string TodoList::getName() {
	return name;
}

vector<Category>& TodoList::getCategories() {
	return categories;
}

void TodoList::showList() {
	cout << "-------------------------" << endl << endl;
	cout << name << endl << endl;
	for (Category c : categories) {
		c.showTasks();
	}
	cout << "-------------------------" << endl << endl;
}

void TodoList::addCategory(Category newCat) {
	categories.push_back(newCat);
}