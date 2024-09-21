#include <iostream>
#include <iomanip>
#include "Task.h"

using namespace std;

Task::Task(const string& desc, const string& deadline, int id) :
	desc(desc),
	deadline(deadline),
	id(id)
{
	fin = false;
}
