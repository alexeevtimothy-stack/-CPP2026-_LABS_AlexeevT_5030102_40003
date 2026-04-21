#pragma once
#include <queue>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include "St.h"

class Teacher {
	std::queue<Mail> inbox;
	std::map<std::string, int> scores;
public:
	void addMail(const Mail& m);
	void checkAll();
	void showScores() const;
};