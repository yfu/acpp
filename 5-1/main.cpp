#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>

#include "split.h"

using std::cout;
using std::cin;
using std::string;
using std::sort;
using std::vector;
using std::setw;
using std::isupper;

bool compare(const string& x, const string& y) {
	if (isupper(x[0]) && islower(y[0])) {
		return false;
	}
	else if (isupper(y[0]) && islower(x[0])) {
		return true;
	} else {
		return x[0] < y[0];
	}
}

vector<string> rotate(string s) {
	vector<string> ret;
	s = s + "$";
	vector<string> words = split(s);
	for (vector<string>::size_type i = 0; i != words.size(); ++i) {
		string permuted = words[i];
		vector<string>::size_type j = (i + 1) % words.size();
		while (j != i) {
			permuted += " " + words[j];
			j = (j + 1) % words.size();
		}
		ret.push_back(permuted);
	}
	sort(ret.begin(), ret.end(), compare);
	return ret;
}

vector<string> halve(vector<string>& v) {
	// Given a string vector v, split it by '$' and put the right part in ret
	// and the left part in v
	vector<string> right;
	for (vector<string>::size_type i = 0; i != v.size(); ++i) {
		string cur = v[i];
		// This is just the right part of one word and it will be push_back()ed to right later.
		string one_right = "";
		string::size_type j = 0;
		while (cur[j] != '$') {
			one_right += cur[j++];
		}
		// Remember to remove '$' as well
		cur.erase(0, j+1);
		v[i] = cur;
		right.push_back(one_right);
	}
	return right;
}

int main() {
	string s = "The quick brown fox";
	vector<string> perm = rotate(s);

	// Two string vectors that hold the left and the right parts of the final resutl.
	vector<string> right;
	right = halve(perm);
	vector<string>& left = perm;
	for (vector<string>::size_type i = 0; i != right.size(); i++) {
		cout << setw(60) << left[i] << "\t" << setw(0) << right[i] << std::endl;
	}
	return 0;
}
