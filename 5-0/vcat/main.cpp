#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;
using std::getline;

vector<string> vcat(const vector<string>& a, const vector<string>& b) {
	vector<string> ret = a;
	for (vector<string>::const_iterator iter = b.begin();
		 iter != b.end(); iter++) {
		ret.push_back(*iter);
	}
	return ret;
}

int main() {
    vector<string> v;
	vector<string> w;
	v.push_back("a");
	v.push_back("bb");
	w.push_back("a");
	w.push_back("bb");
	
	vector<string> x = vcat(v, w);
	for (vector<string>::const_iterator iter = x.begin(); iter != x.end(); iter++) {
		std::cout << *iter << std::endl;
	}
}
