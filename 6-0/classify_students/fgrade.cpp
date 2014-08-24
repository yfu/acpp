#include <list>
#include <algorithm>
#include "Student_info.h"
#include "grade.h"
#include <iostream>

using std::list;
using std::remove_copy_if;
using std::remove_if;

// predicate to determine whether a student failed
bool fgrade(const Student_info& s) {
	return grade(s) < 60;
}

bool pgrade(const Student_info& s) {
	return !fgrade(s);
}

list<Student_info> extract_fails(list<Student_info>& students) {
	list<Student_info> fail;
	remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
	students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());
	return fail;
}

