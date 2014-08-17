#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::max;

string::size_type width(const vector<string>& v) {
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); ++i) {
		maxlen = max(v[i].size(), maxlen);
	}
	return maxlen;
}

vector<string> frame(const vector<string>& v) {
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border = string('*', maxlen + 4);
	// The top border
	ret.push_back(border);
	for(vector<string>::size_type i = 0; i != v.size(); ++i) {
		string pad(maxlen - v[i].size(), ' ');
		ret.push_back("* " + v[i] + pad + " *");
	}
	// The botton border
	ret.push_back(border);
	return ret;
}

int main() {
	vector<string> v;
	string line;
	while (getline(std::cin, line)) {
		v.push_back(line);
	}
	vector<string> f = frame(v);
	for (vector<string>::size_type i; i != f.size(); ++i) {
		std::cout << f[i] << std::endl;
		// std::cout << "abc";
	}
}
