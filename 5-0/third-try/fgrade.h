#ifndef GUARD_fgrade_h
#define GUARD_fgrade_h

#include <vector>
#include "Student_info.h"

using std::vector;

bool fgrade(const Student_info& s);
vector<Student_info> extract_fails(vector<Student_info>& students);
#endif
