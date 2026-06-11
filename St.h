#pragma once
#include <string>
#include "Eq.h"

struct Mail {
	const QuadEq eq;
	Roots ans;
	std::string name;
};

class Student {
public:
	std::string name;
	Student(const std::string& n);
	virtual Roots solve(const QuadEq& eq) const = 0;
	virtual ~Student() = default;
};