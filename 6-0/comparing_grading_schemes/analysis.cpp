#include <iostream>
#include "Student_info.h"
#include <vector>
#include "grade.h"
#include "median.h"
#include <exception>
#include <algorithm>
#include <numeric>

using std::accumulate;
using std::cout;
using std::vector;
using std::endl;
using std::domain_error;
using std::ostream;
using std::string;
using std::transform;

double grade_aux(Student_info s) {
	try {
		return grade(s);
	} catch (domain_error) {
		return grade(s.midterm, s.final, 0);
	}
}
double median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

double average(vector<double> v) {
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return average(grades);
}

double optimistic_median(const Student_info& s) {
	// Compute the students' grade using optimistic median method.
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
	if (nonzero.empty()) {
		return grade(s.midterm, s.final, 0);
	} else {
		return grade(s.midterm, s.final, nonzero);
	}
}

double optimistic_median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}
