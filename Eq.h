#pragma once
#include "cmp.h"

struct QuadEq {
	double a, b, c;
	Roots solve() const;
};