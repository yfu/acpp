#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <algorithm>

#include "analysis.h"
#include "grade.h"
#include "Student_info.h"

using std::domain_error;
using std::cin;
using std::cout;
using std::vector;
using std::streamsize;
using std::string;
using std::endl;
using std::istream;
using std::setprecision;
using std::max;
using std::ostream;

void write_analysis(ostream& out, const string& name, 
					double analysis(const vector<Student_info>&), 
					vector<Student_info>& did, vector<Student_info>& didnt) {
	cout << name << ": median(did) = " << analysis(did)
		 << ", median(didnt) = " << analysis(didnt) << endl;
	return;
}


int main() {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	
	vector<Student_info> did, didnt;
	Student_info student;
	while(read(cin, student)) {
		// students.push_back(record);
		if (did_all_hw(student)) {
			did.push_back(student);
		} else {
			didnt.push_back(student);
		}
	}

	if (did.empty()) {
		cout << "No student did all homework" << endl;
		return 1;
	}
	if (didnt.empty()) {
		cout << "Every student did all homework!" << endl;
	}

	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "optimistic median", optimistic_median_analysis, did, didnt);

	return 0;
}
