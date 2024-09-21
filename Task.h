#include <iostream>
#include <iomanip>
#ifndef TASK_H
#define TASK_H

using namespace std;

class Task {
private:
	string desc;
	string deadline;
	int id;
	bool fin;
public:
	Task(const string& desc, const string& deadline, int id);
	~Task();
	string getDesc();
	string getDeadline();

};

#endif