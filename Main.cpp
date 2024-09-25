#include <iostream>
#include <iomanip>
#include <string>
#include <optional>
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
			cout << "4. Edit Category" << endl;
			cout << "5. Edit Task" << endl;

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
				
				bool flag = false;
				for (Category cat : list.getCategories()) {
					if (cat.getName() == name) {
						cout << endl << "Category already exists." << endl << endl;
						flag = true;
						break;
					}
				}

				if (!flag) {
					Category cat = Category(name);
					list.addCategory(cat);
					cout << endl << "Successfuly added category " << name << " to your list." << endl << endl;
				}
				
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
							cout << endl << "Successfully added task to existing category." << endl << endl;
							flag = true;
							break;
						}
					}
					if (!flag) {
						Category newCat = Category(catName);
						newCat.addTask(newTask);
						list.addCategory(newCat);
						cout << endl << "Successfuly added task to new category." << endl << endl;
					}
				}
				else {
					bool flag = false;
					for (Category &cat : list.getCategories()) {
						if (cat.getName() == "()") {
							cat.addTask(newTask);
							flag = true;
							break;
						}
					}

					if (!flag) {
						Category newCat = Category("()", newTask);
						list.addCategory(newCat);
					}
					
					cout << endl << "Successfuly added uncategorized task." << endl << endl;
				}
				
				break;
			}
			case 4: {
				string newName;
				int choice;

				if (list.getCategories().size() == 0) {
					cout << "ERROR: List is currently empty." << endl << endl;
					break;
				}

				cout << "You have chosen to edit a category." << endl << endl;
				cout << "CATEGORIES:" << endl;
				for (int i = 0; i < list.getCategories().size(); i++) {
					string name = (list.getCategories())[i].getName();
					cout << (i + 1) << ". " << name << endl;
				}
				
				cout << endl << "Please input the number of the category you would like to edit: ";

				while (true) {
					cin >> choice;
					
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "ERROR: Invalid input." << endl;
						cout << "Please input the number of the category you would like to edit: ";
						continue;
					}

					if (choice > list.getCategories().size() || choice <= 0) {
						cout << "ERROR: Input out of range." << endl;
						cout << "Please input the number of the category you would like to edit: ";
					}
					else {
						break;
					}
				}
				cin.ignore();

				cout << "Please input the new name you would like to give this category: ";
				getline(cin, newName);

				Category& cat = (list.getCategories())[choice - 1];
				cat.editCategory(newName);

				cout << endl << "Succesfuly changed category name to '" << newName << "'." << endl << endl;

				break;
			}
			case 5: {
				string newDesc;
				string newDeadline;

				if (list.getCategories().size() == 0) {
					cout << "ERROR: List is currently empty." << endl << endl;
					break;
				}

				cout << "You have chosen to edit a task." << endl << endl;

				cout << "CURRENT TASKS: " << endl;
				int index = 1;
				for (Category& cat : list.getCategories()) {
					for (Task& t : cat.getTasks()) {
						cout << index << ". " << t.getDesc() << " | " << t.getDeadline() << endl;
						index++;
					}
				}
				cout << endl;

				cout << endl << "Please input the number of the task you would like to edit: ";
				
				int choice;
				while (true) {
					cin >> choice;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "ERROR: Invalid input." << endl;
						cout << "Please input the number of the task you would like to edit: ";
						continue;
					}

					if (choice > list.getCategories().size() || choice <= 0) {
						cout << "ERROR: Input out of range." << endl;
						cout << "Please input the number of the task you would like to edit: ";
					}
					else {
						break;
					}
				}
				cin.ignore();

				int temp = 1;
				Task* task = nullptr;
				for (Category& cat : list.getCategories()) {
					for (Task& t : cat.getTasks()) {
						if (temp == choice) {
							cout << temp << " " << choice;
							task = &t;
							break;
						}
						temp++;
					}
				}

				cout << "To edit task description, input 1. To edit task deadline, input 2: ";

				while (true) {
					cin >> choice;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "ERROR: Invalid input." << endl;
						cout << "Please input either 1 or 2: ";
						continue;
					}

					if (choice != 1 && choice != 2) {
						cout << "ERROR: Invalid input." << endl;
						cout << "Please input the number of the task you would like to edit: ";
					}
					else {
						break;
					}
				}
				cin.ignore();

				if (choice == 1) {
					cout << "You have chosen to edit the description of the task." << endl;
					cout << "Please input the new description: ";
					getline(cin, newDesc);
					task->editDesc(newDesc); 
					cout << endl << "Sucessfuly changed task description to '" << newDesc << "'." << endl << endl;
				}
				else {
					cout << "You have chosen to edit the deadline of the task." << endl;
					cout << "Please input the new deadline in the format of MM/DD/YYYY: ";
					getline(cin, newDeadline);
					task->editDeadline(newDeadline);
					cout << endl << "Successfuly changed task deadline to " << newDeadline << "." << endl << endl;

				}

				break;
			}
			}
		} while (choice != 6);
	}

	return 0;
}