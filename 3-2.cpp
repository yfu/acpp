#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::sort;
using std::cin;

std::vector<double> numbers;

int main(int argc, char *argv[])
{
  
  cout <<"Please enter some numbers: ";
  double x;
  while (cin >> x) {
    numbers.push_back(x);
  }
  
  typedef std::vector<double>::size_type vec_sz;
  vec_sz size = numbers.size();
  
  if(size == 0) {
    cout << "You did not enter any numbers! Please try again." << endl;
  }
  sort(numbers.begin(), numbers.end());
  vec_sz mid = size / 2;
  double median = size % 2 == 0 ? (numbers[mid] + numbers[mid-1])/2
    : (numbers[mid]);
  // First quartile: 0th to (mid-1)th
  // Index of the first quartile
  vec_sz half_size = mid;

  vec_sz q1;
  vec_sz q3;
  if (half_size % 2 == 0) {
    q1 = (numbers[half_size] + numbers[half_size-1])/2;
    q3 = (numbers[size] + numbers[half_size + 1]) / 2;
  } else {
    q1 = numbers[half_size];
    q3 = numbers[size - half_size / 2];
  }
  cout << "Quartiles: " << q1 << ", " << median << ", " << q3 << ".";
  return 0;
}

