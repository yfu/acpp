#include <vector>
#include <string>
#include <cctype>

using std::vector;
using std::string;
using std::isspace;

bool space(char i) {
	// Check if the iterator points to a whitespace character.
	return isspace(i);
}

bool not_space(char i) {
	// Return true if the iterator points to a non-whitespace character
	return !space(i);
}
vector<string> split(const string& s) {
	vector<string> ret;

	string::const_iterator j;
	string::const_iterator i = s.begin();
	while (i != s.end()) {
		i = find_if(i, s.end(), not_space);
		j = find_if(i, s.end(), space);
		if (i != s.end()) {
			ret.push_back(string(i, j));
		}
		i = j;
	}
	return ret;
}
