#include <string>
#include <vector>

vector<string> find_url(const string& s) {
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin();
	iter e = s.end();
	while (b != e) {
		begin = url_beg(b, e);

		if (begin != e) {
			iter end = url_end(being, e);
			ret.push_back(string(begin, end));
			begin = end;
		}
	}
	return ret;
	
}
