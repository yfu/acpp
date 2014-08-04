#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <algorithm>

#include "grade.h"
#include "Student_info.h"

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

  for(vector<Student_info>::size_type i = 0; i != students.size(); i++) {
    cout << students[i].name
	 << string(maxlen + 1 - students[i].name.size(), ' ');

    // compute and write the grade
    try {
      double final_grade = grade(students[i]);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
	   << setprecision(prec);
    } catch (domain_error e) {
      cout << e.what();
    }
    cout << endl;
  }
  return 0;
}

  
  // // ask for and read the student's name
  // cout << "Please enter your first name: ";
  // string name;
  // cin >> name;
  // cout << "Please enter your midterm and final exam grades: ";
  // double midterm, final;
  // cin >> midterm >> final;

  // // ask for the homework grade
  // cout << "Enter all your homework grades, "
  //   "followed by end-of-file: ";

  // vector<double> homework;

  // // read the homework grades
  // read_hw(cin, homework);

  // // Compute and generate the final grade, if possible
  // try {
  //   double final_grade = grade(midterm, final, homework);
  //   streamsize prec = cout.precision();
  //   cout << "Your final grade is " << setprecision(3)
  // 	 << final_grade << setprecision(prec) << endl;
  // } catch (domain_error e) {
  //   cout << endl << "You must enter your grades. "
  //     "Please try again." << endl;
  //   return 1;
  // }
  // return 0;

