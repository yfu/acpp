#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
  // square size
  int square_size = 10;

  for (int i = 0; i != square_size; i++) {
    for (int j = 0; j != square_size; j++) {
      cout << '*';
    }
    cout << endl;
  }
  return 0;

  // rectangle...
  // triangle...
}
