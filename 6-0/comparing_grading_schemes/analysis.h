#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include <iostream>
#include "Student_info.h"
#include <vector>

double grade_aux(std::vector<Student_info>::const_iterator i);
/* void write_analysis(std::ostream& out, const std::string& name,  */
/* 					double analysis(std::vector<Student_info>&),  */
/* 					std::vector<Student_info> did, std::vector<Student_info> didnt); */
double median_analysis(const std::vector<Student_info>& students);
double average_analysis(const std::vector<Student_info>& students);
double optimistic_median_analysis(const std::vector<Student_info>& students);
#endif
