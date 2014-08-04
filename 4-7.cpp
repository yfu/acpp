#include <iostream>
#include <vector>

using std::vector;
using std::endl;
using std::cout;
using std::cin;
typedef vector<double>::size_type sz;

int main() {
  vector<double> num;
  num.clear();

  double n;
  while(cin >> n) {
    num.push_back(n);
  }

  cout << num[3] << endl << endl;
  
  double sum = 0;
  int count = 0;

  for(sz i = 0; i != num.size(); ++i) {
    sum += num[i];
    cout << sum << endl;
    count++;
  }
  cout << "The size of the vector is " << num.size() << endl;
  cout << "The sum is " << sum << endl;
  cout << "The count is " << count << endl;
  cout << "The average is " << sum / count << endl;
}
