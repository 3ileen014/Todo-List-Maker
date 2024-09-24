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
			cout << "3. Add Task" << endl;

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
				// edit this so that it doesnt add the new category if it already exists
				string name;

				cout << "You have chosen to create a new category." << endl;
				cout << "Please name the new category: ";
				getline(cin, name);
				Category cat = Category(name);
				list.addCategory(cat);
				cout << endl << "Successfuly added category " << name << " to your list." << endl << endl;
				
				break;
			}
			case 3: {
				string desc;
				string deadline;
				string catName;
				char c;
				
				cout << "You have chosen to add a new task." << endl;
				cout << "Please describe the task: ";
				getline(cin, desc);

				cout << endl << "Please input the deadline in the format of MM/DD/YYYY: ";
				getline(cin, deadline);
				cout << endl << "Categorize this task? (Y/N): ";
				cin >> c;
				cin.ignore();

				Task newTask = Task(desc, deadline);

				while (toupper(c) != 'Y' && toupper(c) != 'N') {
					cout << "ERROR: Invalid choice. Please enter either Y/N: ";
					cin >> c;
					cin.ignore();
				}


				if (toupper(c) == 'Y') {
					cout << "Please enter category name: ";
					getline(cin, catName);
					bool flag = false;
					for (Category& cat : list.getCategories()) {
						if (cat.getName() == catName) {
							cat.addTask(newTask);
							cout << "Successfully added task to existing category." << endl;
							flag = true;
							break;
						}
					}
					if (!flag) {
						Category newCat = Category(catName);
						newCat.addTask(newTask);
						list.addCategory(newCat);
						cout << "Successfuly added task to new category." << endl;
					}
				}
				else {
					// also edit here so that if uncategorized already exists, simply add task
					Category newCat = Category("-", newTask);
					list.addCategory(newCat);
					cout << "Successfuly added uncategorized task." << endl;
				}
				/**/
				break;
			}
			}
		} while (choice != 4);
	}

	return 0;
}