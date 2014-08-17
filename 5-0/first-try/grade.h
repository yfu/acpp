#ifndef GUARD_grade_h
#define GUARD_grade_h

// grade.h
#include <stdexcept>
#include "Student_info.h"

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(const Student_info& s);

#endif


