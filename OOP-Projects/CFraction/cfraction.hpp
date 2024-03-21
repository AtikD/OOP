#pragma once
#include <iostream>

#define TEST_MODE

class CFraction{
	int numerator;
	int denumerator;

	void simplify();
	int gcd(const int a, const int b);

public:
	CFraction();
	//CFraction(std::string str);
	CFraction(const CFraction& f);
	CFraction(int numerator, int denumerator);

	CFraction operator+(const CFraction& frac) const;
	CFraction operator-(const CFraction& frac) const;
	CFraction& operator=(const CFraction& frac);
	CFraction& operator+=(const CFraction& frac);
	CFraction& operator-=(const CFraction& frac);
	friend std::ostream& operator<<(std::ostream& out, const CFraction& frac);
	friend std::ostream& operator<<(std::ostream& out, const CFraction& frac);

};
