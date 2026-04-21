#pragma once
#include "St.h"

class GoodSt : public Student {
public:
	GoodSt(const std::string& n);
	Roots solve(const QuadEq& eq) const;
};