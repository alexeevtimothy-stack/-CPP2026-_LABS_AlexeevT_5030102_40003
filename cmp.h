#pragma once
#include <vector>

inline constexpr double EPS = 1e-6;
using Roots = std::vector<double>;

bool cmpRoots(const Roots& r1, const Roots& r2);