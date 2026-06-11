#include "Eq.h"
#include <cmath>

Roots QuadEq::solve() const {
	if (std::abs(a) < EPS) {
		if (std::abs(b) < EPS) return {};
		return { -c / b };
	}
	double D = b * b - 4 * a * c;
	if (D < -EPS) return {};
	if (std::abs(D) < EPS) return { -b / (2 * a) };
	double sq = std::sqrt(D);
	return { (-b - sq) / (2 * a), (-b + sq) / (2 * a) };
}