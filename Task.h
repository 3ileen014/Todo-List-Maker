#include <iostream>
#include <iomanip>
#ifndef TASK_H
#define TASK_H

using namespace std;

class Task {
private:
	string desc;
	string deadline;
	bool fin;
public:
	Task(const string& desc, const string& deadline);
	~Task() {};
	string getDesc();
	string getDeadline();
	void editDesc(const string& newDesc);
	void editDeadline(const string& newDate);
	void complete();
};

#endif