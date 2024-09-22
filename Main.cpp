
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
	cout << endl << endl;
	cout << "Go ahead and take a look at our menu." << endl << endl;

	menu: {
		do {
			cout << "-------------------------" << endl << endl;
			cout << "Menu: " << endl;
			cout << "1. Add Task" << endl;
			cout << "2. Add Category" << endl;
			cout << "3. Show List" << endl;
			cout << "4. End Program" << endl << endl;
			cout << "-------------------------" << endl << endl;

			cout << "Please input the number of the choice you would like to make: ";
			cin >> choice;
			cin.ignore();

			cout << endl;

			switch (choice) {
			case 1: {
				string desc;
				string date;
				string category;
				char c;

				cout << "You have chosen to add a task." << endl;
				cout << "Input the description of your task: ";
				getline(cin, name);

				cout << "Input the deadline of your task in the form of MM/DD/YYY: ";
				cin >> date;
				cin.ignore();

			categorized: {
				cout << "Should this task be categorized? (Y/N): ";
				cin >> c;
				cin.ignore();

				if (toupper(c) == 'Y') {
					cout << "Input the category that this task should be in: ";
					getline(cin, category);
					cout << endl;
				}
				else if (toupper(c) == 'N') {
					cout << "Task will be uncategorized." << endl;
					category = "U";
				}
				else {
					cout << "ERROR: Please input either Y or N." << endl;
					goto categorized;
				}
				}

			Task newTask = Task(desc, date, category);
			list.addTask(newTask);
			cout << endl;
			break;
			}
			case 2: {
				string name;

				cout << "Input the name of the new category: ";
				getline(cin, name);
				cout << endl;

				list.newCategory(name);

				cout << endl;
				break;
			}
			}
		} while (choice != 4);
	}

	return 0;
}