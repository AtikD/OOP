#include "cfraction.hpp"

CFraction::CFraction(int numerator, int denumerator){
	this->numerator = numerator;
	this->denumerator = denumerator;
	if (numerator != 0 && denumerator != 0)
		simplify();
}

CFraction::CFraction(const CFraction& f):CFraction(f.numerator, f.denumerator){}
CFraction::CFraction():CFraction(0, 0){}

void CFraction::simplify(){
	int gcd = this->gcd(numerator, denumerator);
	numerator /= gcd;
	denumerator /= gcd;
}

int CFraction::gcd(const int a, const int b)
{
	return b == 0 ? a : gcd(b, a % b);
}


CFraction CFraction::operator+(const CFraction& frac) const{
	CFraction res;
	if (this->denumerator == frac.denumerator){
		res.numerator = this->numerator + frac.numerator;
		res.denumerator = this->denumerator;
	} else{
		res.numerator = this->numerator * frac.denumerator +
			frac.numerator * this->denumerator;
		res.denumerator = this->denumerator * frac.denumerator;
	}
	res.simplify();
	return res;
}

CFraction CFraction::operator-(const CFraction& frac) const{
	CFraction res;
	if (this->denumerator == frac.denumerator) {
		res.numerator = this->numerator - frac.numerator;
		res.denumerator = this->denumerator;
	}
	else
	{
		res.numerator = this->numerator * frac.denumerator -
			frac.numerator * this->denumerator;
		res.denumerator = this->denumerator * frac.denumerator;
	}
	res.simplify();
	return res;
}


CFraction& CFraction::operator=(const CFraction& frac){
	if (this != &frac)
	{
		this->denumerator = frac.denumerator;
		this->numerator = frac.numerator;
	}
	return *this;
}

CFraction& CFraction::operator+=(const CFraction& frac){
	*this = *this + frac;
	return *this;
}

CFraction& CFraction::operator-=(const CFraction& frac) {
	*this = *this - frac;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const CFraction& frac)
{
	out << frac.numerator << '/' << frac.denumerator ;
#ifdef TEST_MODE
	out << '\n';
#endif
	return out;
}

