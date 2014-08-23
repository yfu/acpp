#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;
using std::getline;
using std::copy;

vector<string> vcat(const vector<string>& a, const vector<string>& b) {
	vector<string> ret = a;
	// Instead of a loop, use copy from standard library:
	copy(b.begin(), b.end(), back_inserter(ret));
	return ret;
}

int main() {
    vector<string> v;
	vector<string> w;
	v.push_back("v");
	v.push_back("vv");
	w.push_back("w");
	w.push_back("ww");
	
	vector<string> x = vcat(v, w);
	for (vector<string>::const_iterator iter = x.begin(); iter != x.end(); iter++) {
		std::cout << *iter << std::endl;
	}
}
