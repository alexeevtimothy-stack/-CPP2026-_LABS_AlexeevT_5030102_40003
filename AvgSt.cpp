#include "AvgSt.h"

AvgSt::AvgSt(const std::string& n, double p)
	: Student(n), prob(p), rng(std::random_device{}()) {
}

Roots AvgSt::solve(const QuadEq& eq) const {
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	if (dist(rng) < prob) return eq.solve();
	return { 0.0 };
}