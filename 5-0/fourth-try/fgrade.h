#ifndef GUARD_fgrade_h
#define GUARD_fgrade_h

#include <list>
#include "Student_info.h"

bool fgrade(const Student_info& s);
std::list<Student_info> extract_fails(std::list<Student_info>& students);
#endif
