#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using std::domain_error;
using std::cin;
using std::cout;
using std::vector;
using std::streamsize;
using std::string;
using std::endl;
using std::istream;
using std::setprecision;

double median(std::vector<double> vec) {
  typedef std::vector<double>::size_type vec_sz;
  vec_sz size = vec.size();
  if (size == 0) {
    throw domain_error("median of an empty vector");
  }
  sort(vec.begin(), vec.end());
  vec_sz mid = size / 2;
  return size % 2 == 0 ? (vec[mid-1] + vec[mid])/2 : vec[mid] ;
}

double grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const std::vector<double>& hw) {
  if (hw.size() == 0) {
    throw std::domain_error("student has done no homework");  
  }
  return grade(midterm, final, median(hw));
}

istream& read_hw(istream& in, vector<double>& hw) {
  // Fill in this part
  if (in) {
    // get rid of previous contents
    hw.clear();
    double x;
    while(in >> x) {
      hw.push_back(x);
    }
    in.clear();
  }
  return in;
}

int main() {
  // ask for and read the student's name
  cout << "Please enter your first name: ";
  string name;
  cin >> name;
  cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  // ask for the homework grade
  cout << "Enter all your homework grades, "
    "followed by end-of-file: ";

  vector<double> homework;

  // read the homework grades
  read_hw(cin, homework);

  // Compute and generate the final grade, if possible
  try {
    double final_grade = grade(midterm, final, homework);
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
	 << final_grade << setprecision(prec) << endl;
  } catch (domain_error e) {
    cout << endl << "You must enter your grades. "
      "Please try again." << endl;
    return 1;
  }
  return 0;
}
