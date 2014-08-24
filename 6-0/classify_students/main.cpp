#include <vector>
#include <list>
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
using std::list;

int main() {
  list<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  while(read(cin, record)) {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  // sort(students.begin(), students.end(), compare);
  students.sort(compare);
  // for(list<Student_info>::size_type i = 0; i != students.size(); i++) {
  //   cout << students[i].name
  // << string(maxlen + 1 - students[i].name.size(), ' ');
  // }

  list<Student_info> pass, fail;
  fail = extract_fails(students);
  pass = students;
  cout << "Students who failed the exam:" << endl;
  for (list<Student_info>::const_iterator i = fail.begin(); i != fail.end(); ++i) {
	  cout << "Name: " << i->name << " Midterm: " << i->midterm << " Final exam: "
		   << i->final << " Homework: ";
	  for (vector<double>::size_type j = 0; j != i->homework.size(); ++j) {
		  cout << i->homework[j] << " ";
	  }
	  cout << endl;
  }

  cout << "Students who passed the exam:" << endl;
  for (list<Student_info>::const_iterator i = students.begin(); i != students.end(); ++i) {
	  cout << "Name: " << i->name << " Midterm: " << i->midterm << " Final exam: "
		   << i->final << " Homework: ";
	  for (vector<double>::size_type j = 0; j != i->homework.size(); ++j) {
		  cout << i->homework[j] << " ";
	  }
	  cout << endl;
  }
}
