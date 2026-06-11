#include "cmp.h"
#include <algorithm>
#include <cmath>

bool cmpRoots(const Roots& r1, const Roots& r2) {
	Roots s1 = r1, s2 = r2;
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());
	if (s1.size() != s2.size()) return false;
	for (size_t i = 0; i < s1.size(); ++i)
		if (std::abs(s1[i] - s2[i]) > EPS) return false;
	return true;
}