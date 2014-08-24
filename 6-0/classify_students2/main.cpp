#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <algorithm>

#include "grade.h"
#include "Student_info.h"
#include "fgrade.h"

using std::domain_error;
using std::cin;
using std::cout;
using std::vector;
using std::streamsize;
using std::string;
using std::endl;
using std::istream;
using std::setprecision;
using std::max;

int main() {
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  while (read(cin, record)) {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  // sort(students.begin(), students.end(), compare);
  cout << "Student names: " << endl;
  for (vector<Student_info>::size_type i = 0; i<students.size(); ++i) {
	  cout << students[i].name << endl;
  }
  
  // Output the failing and passing students
  vector<Student_info> fail = extract_fails(students);
  vector<Student_info> pass = students;


  if (!pass.empty()) {
	  cout << "The students who passed the exam: " << endl;
	  for (vector<Student_info>::size_type i = 0; i != pass.size(); ++i) {
		  cout << pass[i].name << ": Final exam grade " << pass[i].final << " and Midterm grade " << pass[i].midterm
			   << "and homework grades ";
		  for(vector<double>::size_type j = 0; j != pass[i].homework.size(); ++j) {
			  cout << pass[i].homework[j] << " ";
		  }
		  cout << endl;
	  }
  }

  if (!fail.empty()) {
	  cout << "The students who failed the exam: " << endl;
	  for (vector<Student_info>::size_type i = 0; i != fail.size(); ++i) {
		  cout << fail[i].name << ": Final exam grade " << fail[i].final << " and Midterm grade " << fail[i].midterm
			   << " and homework grades ";
		  for (vector<double>::size_type j = 0; j != fail[i].homework.size(); ++j) {
			  cout << fail[i].homework[j] << " ";
		  }
		  cout << endl;
	  }
  }
  return 0;
}
