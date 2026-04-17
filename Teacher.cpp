#include <iostream>
#include <queue>
#include <map>
#include <fstream>
#include <random>

#include <iomanip>

#include <windows.h>  
#include <clocale>

const double EPS = 1e-6;
using Roots = std::vector<double>;

struct QuadEq {
	double a, b, c;

	Roots solve() const {
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
};

bool cmpRoots(const Roots& r1, const Roots& r2) {
	Roots s1 = r1, s2 = r2;
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());
	if (s1.size() != s2.size()) return false;
	for (size_t i = 0; i < s1.size(); ++i)
		if (std::abs(s1[i] - s2[i]) > EPS) return false;
	return true;
}

struct Mail {
	QuadEq eq;
	Roots ans;
	std::string name;
};

class Student {
public:
	std::string name;
	Student(std::string n) : name(n) {}
	virtual Roots solve(const QuadEq& eq) = 0;
};

class GoodSt : public Student {
public:
	GoodSt(std::string n) : Student(n) {}
	Roots solve(const QuadEq& eq) { return eq.solve(); }
};

class AvgSt : public Student {
	double prob;
	std::mt19937 rng;
public:
	AvgSt(std::string n, double p)
		: Student(n), prob(p), rng(std::random_device{}()) {
	}

	Roots solve(const QuadEq& eq) {
		std::uniform_real_distribution<double> dist(0.0, 1.0);
		if (dist(rng) < prob) return eq.solve();
		return { 0.0 };
	}
};

class BadSt : public Student {
public:
	BadSt(std::string n) : Student(n) {}
	Roots solve(const QuadEq& eq) { return { 0.0 }; }
};

class Teacher {
	std::queue<Mail> inbox;
	std::map<std::string, int> scores;
public:
	void addMail(const Mail& m) {
		inbox.push(m);
		if (scores.find(m.name) == scores.end()) { scores[m.name] = 0; }
	}

	void checkAll() {
		while (!inbox.empty()) {
			Mail m = inbox.front();
			inbox.pop();
			if (cmpRoots(m.eq.solve(), m.ans)) {
				scores[m.name]++;
			}
		}
	}

	void showScores() const {
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
};

int main() {

	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	std::setlocale(LC_ALL, "UTF-8");

	std::vector<QuadEq> eqs;
	std::ifstream fin("equations.txt");

	double a, b, c;
	while (fin >> a >> b >> c) eqs.push_back({ a, b, c });

	std::vector<std::unique_ptr<Student>> stds;
	stds.push_back(std::make_unique<GoodSt>("Саша"));
	stds.push_back(std::make_unique<GoodSt>("Глаша"));
	stds.push_back(std::make_unique<AvgSt>("Ира", 0.5));
	stds.push_back(std::make_unique<AvgSt>("Михаил", 0.8));
	stds.push_back(std::make_unique<BadSt>("Даниил"));

	Teacher tch;

	for (const auto& eq : eqs) {
		for (const auto& s : stds) {
			tch.addMail({ eq, s->solve(eq), s->name });
		}
	}

	tch.checkAll();
	tch.showScores();

	return 0;
}
