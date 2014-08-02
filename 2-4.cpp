#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  cout << "What is your name? ";
  string name;
  cin >> name;
  cout << endl;
  const string greeting = "Hello, " + name + "!";
  
  int pad = 3;
  const string::size_type row = 2 * pad + 3;
  const string::size_type col = greeting.size() + 2 * pad + 2;

  for (int r = 0; r != row; r++) {
    int c = 0;
    while(c != col) {

      if(c==1+pad && r==1+pad) {
	// Output the greeting here
	cout << greeting;
	c += greeting.size();
      } else {
	if(r==0 || r==row-1 || c==0 || c==col-1) {
	  cout << "*";
	  c++;
	}
	else if(r!=1+pad) {
	  // Print multiple spaces...
	  string spaces(greeting.size() + 2*pad, ' ');
	  cout << spaces;
	  c += greeting.size() + 2*pad;
	}
	else {
	  cout << " ";
	  c++;
	}
      }   
    }
    cout << endl;
  }
  return 0;
}

