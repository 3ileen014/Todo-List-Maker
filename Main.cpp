
#include <iostream>
#include <iomanip>
#include <string>
#include "Task.h"
#include "TodoList.h"

using namespace std;

int main()
{
	int choice;
	string name;

	cout << "Welcome to your own customizable todo list!" << endl << endl;
	cout << "Please name your list: ";
	getline(cin, name);
	TodoList list = TodoList(name);
	cout << endl;
	cout << "Go ahead and take a look at our menu." << endl << endl;

	menu: {
		do {
			cout << "=========================" << endl << endl;
			cout << "Menu: " << endl;
			cout << "1. Show List" << endl;
			cout << "2. Add Category" << endl;

			cout << endl << "=========================" << endl << endl;

			cout << "Please input the number of the choice you would like to make: ";
			cin >> choice;
			cin.ignore();

			cout << endl;

			switch (choice) {
			case 1: {
				if ((list.getCategories()).empty()) {
					cout << "Your list is currently empty." << endl << endl;
				}
				else {
					cout << "Here is your current list:" << endl << endl;
					list.showList();
				}
				
				break;
			}
			case 2: {
				string name;

				cout << "You have chosen to create a new category." << endl;
				cout << "Please name the new category: ";
				getline(cin, name);
				Category cat = Category(name);
				list.addCategory(cat);
				cout << endl << "You have successfuly added " << name << " to your list." << endl << endl;
				
				break;
			}
			}
		} while (choice != 4);
	}

	return 0;
}