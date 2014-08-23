#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;
using std::getline;

vector<string> vcat(const vector<string>& a, const vector<string>& b) {
	vector<string> ret = a;
	// Instead of a loop, use standard library:
	ret.insert(ret.end(), b.begin(), b.end());
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
