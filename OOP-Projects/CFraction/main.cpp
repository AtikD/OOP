#include "cfraction.hpp"

int main(){
	CFraction f1, f2(2, 3), f3(f2);
	CFraction f4 = f2;
	CFraction f5{ 1,5 };
	CFraction f6 = f4 + f5;
	CFraction f7 = f4 - f5;
	f4 += f5;
	f4 -= f5;
	CFraction f8(8, 16);
	std::cout << f1 << f2  << f3 << f4 << f5 << f6 << f7 << f4 << f8;

	return 0;
}