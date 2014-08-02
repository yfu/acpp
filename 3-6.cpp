#include <iostream>
#include <ios>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

int main(){
  cout << "Input your first name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;
  
  // ask for and raed the midterm and final grades
  cout << "Please enter your midterm and final grades: ";
  double midterm, final;
  cin >> midterm >> final;

  // ask for homework grade
  cout << "Please enter your homework grades: ";
  int count = 0;
  double sum = 0;
  
  double x;
  while(cin >> x) {
    ++count;
    sum += x;
  }
  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
       << 0.2 * midterm + 0.4 * final + (count==0?0:0.4 * sum / count)
       << setprecision(prec) << endl;
  return 0;
}
