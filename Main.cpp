
#include <iostream>
#include <iomanip>
#include "Task.h"
#include "TodoList.h"

using namespace std;

int main()
{
	string desc = "do this";
	string deadline = "10/28/2006";
	int id = 2;
	string category = "School";
	Task task1 = Task(desc, deadline, category, id);

	cout << task1.getDesc() << endl;
	cout << task1.getDeadline() << endl;

	task1.editDesc("do that");
	cout << task1.getDesc() << endl;


	TodoList list1("List #1");

	list1.addTask(task1);
	list1.showList();

	Task task2 = Task("do this", deadline, category, 3);
	list1.addTask(task2);
	list1.showList();

	Task task3 = Task("do what", deadline, "Work", 4);
	list1.addTask(task3);
	list1.showList();

	list1.removeTask(2, "School");
	list1.showList();
}
