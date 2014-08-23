#include <algorithm>
#include <iostream>
#include <string>

using std::equal;
using std::string;

bool is_palindrome(string s) {
	return equal(s.begin(), s.end(), s.rbegin());
}

int main() {
	string a = "abcdcba";
	std::cout << " is " << a << " a palindrome?" << " " << is_palindrome(a) << std::endl;
	string b = "abcdefg";
	std::cout << " is " << b << " a palindrome?" << " " << is_palindrome(b) << std::endl;
}
