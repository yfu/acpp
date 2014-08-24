#ifndef GUARD_extract_fails_h
#define GUARD_extract_fails_h

// predicate to determine whether a student failed
/* bool fgrade(const Student_info& s) { */
/* 	return grade(s) < 60; */
/* } */

#include <vector>
#include "Student_info.h"

// Separate passing and failing student records: first try
std::vector<Student_info> extract_fails(std::vector<Student_info>& students);

#endif
