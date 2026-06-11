#pragma once
#include <random>
#include "St.h"

class AvgSt : public Student {
	double prob;
	mutable std::mt19937 rng;
public:
	AvgSt(const std::string& n, double p);
	Roots solve(const QuadEq& eq) const;
};