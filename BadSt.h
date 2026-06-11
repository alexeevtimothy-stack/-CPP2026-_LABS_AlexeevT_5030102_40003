#pragma once
#include "St.h"

class BadSt : public Student {
public:
	BadSt(const std::string& n);
	Roots solve(const QuadEq& eq) const;
};