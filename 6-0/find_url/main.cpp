#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using std::endl;
using std::vector;
using std::string;
using std::isalpha;
using std::isalnum;
using std::search;
using std::cout;

bool not_url_char(char c)
{
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";

	// if (isalnum(c)) {
	// 	return false;
	// } else if (find(url_ch.begin(), url_ch.end(), c) == url_ch.end()) {
	// 	return true;
	// } else {
	// return false;
	// }
	if (isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end()) {
		return false;
	}
	return true;
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
	return find_if(b, e, not_url_char);
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e) 
{
	static const string sep = "://";

	typedef string::const_iterator iter;
	iter i = b;
	while ( (i = search(i, e, sep.begin(), sep.end())) != e ) {
		if (i != b && i + sep.size() != e) {
			iter beg = i;
			while (beg != b && isalpha(beg[-1])) {
				--beg;
			}

			if (beg != i && !not_url_char(i[sep.size()])) {
				return beg;
			}
		}
		i += sep.size();
	}
	return e;
}

vector<string> find_url(const string& s) {
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin();
	iter e = s.end();
	while (b != e) {
		b = url_beg(b, e);
		if (b != e) {
			iter after = url_end(b, e);
			ret.push_back(string(b, after));
			b = after;
		}
	}
	return ret;
	
}

int main(int argc, char *argv[])
{
    vector<string> v = find_url("This is http://www.google.com and ftp://yfu.me Enjoy!");
	vector<string>::const_iterator i = v.begin();
	while (i != v.end()) {
		std::cout << *i << endl;;
		i++;
	}
    return 0;
}
