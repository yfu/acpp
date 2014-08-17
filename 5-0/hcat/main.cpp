#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::string;
using std::max;

string::size_type width(const vector<string>& v) {
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); ++i) {
		maxlen = max(v[i].size(), maxlen);
	}
	return maxlen;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right) {
	string::size_type maxlen = width(left);
	vector<string> ret;

	vector<string>::size_type i = 0, j = 0;
	while (i != left.size() || j != right.size()) {
		string s;
		if (i != left.size()) {
			s = left[i++];
		}
		s += string(maxlen + 1 - s.size(), ' ');
		if (j != right.size()) {
			s += right[j++];
		}
		ret.push_back(s);
	}
	return ret;
}

int main() {
	vector<string> left;
	left.push_back("aaa");
	vector<string> right;
	right.push_back("bbbbb");
	right.push_back("ccccdfawdf");
	vector<string> h = hcat(left, right);
	for(vector<string>::const_iterator iter = h.begin(); iter != h.end(); iter++) {
		std::cout << *iter << std::endl;
	}
}
