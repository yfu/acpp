#include <vector>
#include <string>
#include "split.h"
#include <iostream>

using std::string;
using std::cin;
using std::vector;
using std::cout;

int main() {
	string s;
	vector<string> v;
	// Read and split each line of input
	while (getline(cin, s)) {
		v = split(s);
	}
	// Now output each word;
	for (vector<string>::size_type i; i != v.size(); ++i) {
		cout << v[i] << std::endl;
	}
	return 0;
}
