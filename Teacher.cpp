#include "Teacher.h"

void Teacher::addMail(const Mail& m) {
	inbox.push(m);
	scores.try_emplace(m.name, 0);
}

void Teacher::checkAll() {
	while (!inbox.empty()) {
		Mail m = inbox.front();
		inbox.pop();
		if (cmpRoots(m.eq.solve(), m.ans)) {
			scores[m.name]++;
		}
	}
}

void Teacher::showScores() const {
	std::cout << std::string(35, '=') << "\n";
	std::cout << "ТАБЛИЦА УСПЕВАЕМОСТИ" << "\n";
	std::cout << std::string(35, '=') << "\n";

	std::cout << "СТУДЕНТ" << "\t\t" << "ОЦЕНКА\n";
	std::cout << std::string(35, '-') << "\n";

	for (const auto& p : scores) {
		std::cout << p.first << "\t\t" << p.second << "\n";
	}
	std::cout << std::string(35, '=') << "\n";
}