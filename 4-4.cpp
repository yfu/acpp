#include <iostream>
#include <iomanip>
#include <vector>

using std::vector;
using std::string;
using std::streamsize;
using std::cout;
using std::endl;
using std::setw;


int digits(int);

int main() {
	const int max_base = 999;
	const int max_base_len = digits(max_base);
	const int max_square_len = digits(max_base * max_base);
	
	for(int i=1; i <= max_base; i++) {
		cout << setw(max_base_len + 1) << i << setw(max_square_len + 1) << i*i << endl;
	}
}

int digits(int n) {
	int length = 0;
	while(n) {
		length++;
		n /= 10;
	}
	return length;
}
