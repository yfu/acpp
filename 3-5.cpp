#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::sort;
using std::streamsize;
using std::setprecision;
using std::endl;
using std::vector;

int main(int argc, char *argv[])
{
  int max_grade = 3;
  vector<string> s_names;
  vector<double> s_grades;
  cout << "Please enter the first student's name: " << endl;
  string name;
  
  while( cin >> name ) {
    cout << "Enter " << max_grade << " grades for " << name << ": ";
    int grade_count = 0;
    double grade;
    s_names.push_back(name);
    double sum = 0;
    int i = 0;
    while(grade_count < max_grade && cin >> grade) {
      ++i;
      sum += grade;
      ++grade_count;
    }
    s_grades.push_back(sum / i);
    cout << "Next student's name" << endl;
  }

  cout << "** Now I will output students' name and grade **" << endl;

  vector<string>::size_type i = 0;
  streamsize prec = cout.precision();
  while(i < s_names.size()) {
    cout << "Name: " << s_names[i] << endl;
    cout << "Grade: " << setprecision(2) << s_grades[i] << setprecision(prec) << endl;
    ++i;
  }
  return 0;
}
