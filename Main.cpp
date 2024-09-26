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
			cout << "4. Edit Category" << endl;
			cout << "5. Edit Task" << endl;
			cout << "6. Delete Category" << endl;
			cout << "7. Delete Task" << endl;
			cout << "8. Complete Task" << endl;
			cout << "9. Clear List" << endl;
			cout << "10. End Program" << endl;

			cout << endl << "=========================" << endl << endl;

			cout << "Please input the number of the choice you would like to make: ";

			if (!(cin >> choice)) {
				cout << endl << "ERROR: Invalid choice. Please enter a valid integer." << endl << endl;
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			cin.ignore();

			cout << endl;

			switch (choice) {
			case 1: { // show list
				if ((list.getCategories()).empty()) {
					cout << "ERROR: List is currently empty." << endl << endl;
				}
				else {
					cout << "Here is your current list:" << endl << endl;
					list.showList();
				}

				break;
			}
			case 2: { // add category
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
			case 3: { // add task
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
					for (Category& cat : list.getCategories()) {
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
			case 4: { // edit category
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
			case 5: { // edit task
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

					if (choice >= index || choice <= 0) {
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
			case 6: { // delete category
				int index;

				if (list.getCategories().size() == 0) {
					cout << "ERROR: List is currently empty." << endl << endl;
					break;
				}

				cout << "You have chosen to delete a category." << endl << endl;
				cout << "CATEGORIES:" << endl;
				for (int i = 0; i < list.getCategories().size(); i++) {
					string name = (list.getCategories())[i].getName();
					cout << (i + 1) << ". " << name << endl;
				}

				cout << endl << "Please input the number of the category you would like to delete: ";

				while (true) {
					cin >> index;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "ERROR: Invalid input." << endl;
						cout << "Please input the number of the category you would like to delete: ";
						continue;
					}

					if (index > list.getCategories().size() || index <= 0) {
						cout << "ERROR: Input out of range." << endl;
						cout << "Please input the number of the category you would like to delete: ";
					}
					else {
						break;
					}
				}
				cin.ignore();

				char c;

				if ((list.getCategories()[index - 1]).getTasks().size() > 0) {
					cout << "WARNING: Selected category currently has tasks." << endl;
					cout << "Deleting category will also permanently delete tasks. Continue? (Y/N): ";
					cin >> c;
					while (toupper(c) != 'Y' && toupper(c) != 'N') {
						cout << "ERROR: Invalid choice. Please enter either Y/N: ";
						cin >> c;
						cin.ignore();
					}

					if (toupper(c) == 'Y') {
						list.deleteCategory(index - 1);
						cout << endl << "Successfuly deleted category." << endl << endl;
					}
					else {
						cout << endl << "Category has not been deleted." << endl << endl;
						continue;
					}
				}
				else {
					list.deleteCategory(index - 1);
					cout << endl << "Successfuly deleted category." << endl << endl;
				}

				break;
			}
			case 7: { // delete task
				int index;

				if (list.getCategories().size() == 0) {
					cout << "ERROR: List is currently empty." << endl << endl;
					break;
				}

				cout << "You have chosen to delete a task." << endl << endl;

				cout << "CURRENT TASKS: " << endl;
				index = 1;
				for (Category& cat : list.getCategories()) {
					for (Task& t : cat.getTasks()) {
						cout << index << ". " << t.getDesc() << " | " << t.getDeadline() << endl;
						index++;
					}
				}
				cout << endl;

				cout << endl << "Please input the number of the task you would like to delete: ";

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

					if (choice >= index || choice <= 0) {
						cout << "ERROR: Input out of range." << endl;
						cout << "Please input the number of the task you would like to edit: ";
					}
					else {
						break;
					}
				}
				cin.ignore();

				char c;
				int temp = 1;
				int indexInCat;
				for (Category& cat : list.getCategories()) {
					indexInCat = 0;
					for (Task& t : cat.getTasks()) {
						if (temp == choice) {
							cout << "WARNING: This action will permanently delete this task." << endl;
							cout << "Continue? (Y/N): ";

							cin >> c;
							while (toupper(c) != 'Y' && toupper(c) != 'N') {
								cout << "ERROR: Invalid choice. Please enter either Y/N: ";
								cin >> c;
								cin.ignore();
							}

							if (toupper(c) == 'Y') {
								cat.deleteTask(indexInCat);
								cout << endl << "Successfuly deleted task." << endl << endl;
							}
							else {
								cout << endl << "Task has not been deleted." << endl << endl;
							}

							break;
						}
						temp++;
						indexInCat++;
					}
				}

				break;
			}
			case 8: { // mark task as completed
				
				if (list.getCategories().size() == 0) {
					cout << "ERROR: List is currently empty." << endl << endl;
					break;
				}

				cout << "You have chosen to mark a task as completed." << endl << endl;

				cout << "CURRENT TASKS: " << endl;
				int index = 1;
				for (Category& cat : list.getCategories()) {
					for (Task& t : cat.getTasks()) {
						cout << index << ". " << t.getDesc() << " | " << t.getDeadline() << endl;
						index++;
					}
				}

				cout << endl << "Please input the number of the task you would like to mark as completed: ";

				int choice;
				while (true) {
					cin >> choice;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "ERROR: Invalid input." << endl;
						cout << "Please input the number of the task that has been completed: ";
						continue;
					}

					if (choice >= index || choice <= 0) {
						cout << "ERROR: Input out of range." << endl;
						cout << "Please input the number of the task that has been completed: ";
					}
					else {
						break;
					}
				}
				cin.ignore();

				char c;
				int temp = 1;
				int indexInCat;
				Task task = Task("","");
				for (Category& cat : list.getCategories()) {
					indexInCat = 0;
					for (Task& t : cat.getTasks()) {
						if (temp == choice) {
							task = t;
							cat.deleteTask(indexInCat);
							break;
						}
						temp++;
						indexInCat++;
					}
				}

				bool flag = false;
				for (Category& cat : list.getCategories()) {
					if (cat.getName() == "Completed") {
						cat.addTask(task);
						flag = true;
						break;
					}
				}
				if (!flag) {
					Category newCat = Category("Completed");
					newCat.addTask(task);
					list.addCategory(newCat);
				}
				
				cout << endl << "Successfuly marked task as completed." << endl << endl;

				break;
			}
			case 9: { // clear list
				if (list.getCategories().size() == 0) {
					cout << "ERROR: List is already empty." << endl << endl;
					break;
				}

				cout << "WARNING: This action will permanently delete your current list." << endl;
				cout << "Continue? (Y/N): ";

				char c;
				cin >> c;
				while (toupper(c) != 'Y' && toupper(c) != 'N') {
					cout << "ERROR: Invalid choice. Please enter either Y/N: ";
					cin >> c;
					cin.ignore();
				}

				if (toupper(c) == 'Y') {
					list.clearList();
					cout << endl << "Succesfuly cleared list." << endl << endl;
				}
				else {
					cout << endl << "List has not been cleared." << endl << endl;
				}

				break;
			}
			default: {
				if (choice != 10) {
					cout << "ERROR: Invalid choice. Please select an option on the menu." << endl << endl;
				}
			}
			}
		} while (choice != 10);

		cout << "Thank you for using this Todo List program." << endl;
		cout << "Goodbye!" << endl;
	}

	return 0;
}