#include <iostream>
#include <iomanip>
#include "Task.h"

using namespace std;

Task::Task(const string& desc, const string& deadline, const string& category, int id) :
	desc(desc),
	deadline(deadline),
	category(category),
	id(id)
{
	fin = false;
}

string Task::getDesc() {
	return desc;
}

string Task::getDeadline() {
	return deadline;
}

string Task::getCategory() {
	return category;
}

int Task::getID() {
	return id;
}

void Task::editDesc(const string& newDesc) {
	desc = newDesc;
}

void Task::editDeadline(const string& newDate) {
	deadline = newDate;
}

void Task::complete() {
	fin = true;
}