#include <iostream>
#include <iomanip>
#ifndef TASK_H
#define TASK_H

using namespace std;

class Task {
private:
	string desc;
	string deadline;
	string category;
	int id;
	bool fin;
public:
	Task(const string& desc, const string& deadline, const string& category, int id);
	~Task() {};
	string getDesc();
	string getDeadline();
	string getCategory();
	int getID();
	void editDesc(const string& newDesc);
	void editDeadline(const string& newDate);
	void complete();
};

#endif