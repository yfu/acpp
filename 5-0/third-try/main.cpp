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

  while(read(cin, record)) {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare);

  // for(vector<Student_info>::size_type i = 0; i != students.size(); i++) {
  //   cout << students[i].name
  // << string(maxlen + 1 - students[i].name.size(), ' ');
  // }

  vector<Student_info> pass, fail;
  fail = extract_fails(students);
  pass = students;
  cout << "Students who failed the exam:" << endl;
  for (vector<Student_info>::size_type i = 0; i != fail.size(); ++i) {
	  cout << "Name: " << fail[i].name << " Midterm: " << fail[i].midterm << " Final exam: "
		   << fail[i].final << " Homework: ";
	  for (vector<double>::size_type j = 0; j != fail[i].homework.size(); ++j) {
		  cout << fail[i].homework[j] << " ";
	  }
	  cout << endl;
  }

  cout << "Students who passed the exam:" << endl;
  for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
	  cout << "Name: " << students[i].name << " Midterm: " << students[i].midterm << " Final exam: "
		   << students[i].final << " Homework: ";
	  for (vector<double>::size_type j = 0; j != students[i].homework.size(); ++j) {
		  cout << students[i].homework[j] << " ";
	  }
	  cout << endl;
  }

  
	
}
