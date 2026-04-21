#include "GoodSt.h"

GoodSt::GoodSt(const std::string& n) : Student(n) {}
Roots GoodSt::solve(const QuadEq& eq) const { return eq.solve(); }