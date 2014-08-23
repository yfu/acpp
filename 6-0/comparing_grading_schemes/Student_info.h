#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream>
#include <string>
#include <vector>

struct Student_info
{
  std::string name;
  double midterm, final;
  std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read(std::istream&, std::vector<double>&);

bool did_all_hw(const Student_info& s);

#endif
