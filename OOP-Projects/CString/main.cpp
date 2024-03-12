#include <iostream>
#include "string.h"

int main()
{
	CString s1, s2(s1);
	CString s3("help", 2);
	CString s4(24, '*');
	CString s5("Repository with OOP materials and projects by 'Programming Base' (2nd term)", 46, 19);
	s5.clear();
	s5.print();
	return 1;
}
/*
// ������ main()
int main() {
	String str_1;
	String str_2("This is an example sentence. And it's cool.");
	String str_3(str_2);
	String str_4("Very important text for save", 10);
	String str_5(20, '*');
	String str_6(str_4, 5, 3);

	std::cout << "String str_1;\n";
	str_1.print();
	std::cout << std::endl << "String str_2(\"Hello\");\n";
	str_2.print();
	std::cout << std::endl << "String str_3(str_2);\n";
	str_3.print();
	std::cout << std::endl << "String str_4(\"Very important text for save\", 10);\n";
	str_4.print();
	std::cout << std::endl << "String str_5(20, \'*\');\n";
	str_5.print();
	std::cout << std::endl << "String str_6(str_4, 5, 3);\n";
	str_6.print();
	std::cout << std::endl;

	std::cout << "str_1.empty();\n" <<
		(str_1.empty() ? "true" : "false") << std::endl;
	std::cout << "str_4.size();\n" <<
		str_4.size() << std::endl;
	std::cout << "str_4.capacity();\n" <<
		str_4.capacity() << std::endl;
	std::cout << "str_4.data();\n" <<
		str_4.data() << std::endl;

	str_4.clear();
	std::cout << "str_4.clear();\n";
	str_4.print();
	std::cout << std::endl;

	str_4.push_back('H');
	str_4.push_back('i');
	str_4.push_back(',');
	str_4.push_back(' ');
	str_4.push_back('B');
	str_4.push_back('o');
	str_4.push_back('b');
	std::cout << "str_4.push_back('H'); str_4.push_back('i'); ... str_4.push_back('b');\n";
	str_4.print();
	std::cout << std::endl;

	str_2.erase(10, 8);
	std::cout << "str_2.erase(10, 8);\n";
	str_2.print();
	std::cout << std::endl;

	str_5.resize(10);
	str_5.resize(15, '+');
	std::cout << "str_5.resize(15);str_5.resize(25, '+');\n";
	str_5.print();
	std::cout << std::endl;

	str_2.swap(str_5);
	std::cout << "str_2.swap(str_5);\nstr_2: ";
	str_2.print();
	std::cout << "\nstr_5: ";
	str_5.print();
	std::cout << std::endl;

	char buf[20];
	size_t length = str_2.copy(buf, 2, 9);
	buf[length] = '\0';
	std::cout << "size_t length = str_2.copy(buf, 2, 9);\nbuf: " << buf;
	std::cout << std::endl;

	str_2.assign(str_5);
	std::cout << "str_2.assign(str_5);\nstr_2: ";
	str_2.print();
	std::cout << "\nstr_5: ";
	str_5.print();
	std::cout << std::endl;

	std::cout << "str_2.compare(str_5);\n";
	std::cout << str_2.compare(str_5);
	std::cout << std::endl;

	String str_7("Hello"), str_8("Hello It\'s Me");
	std::cout << "String str_7(\"Hello\");\n";
	str_7.print();
	std::cout << std::endl << "String str_8(\"Hello It\'s Me\");\n";
	str_8.print();
	std::cout << std::endl << "str_7.compare(str_8);\n";
	std::cout << str_7.compare(str_8);
	std::cout << std::endl << "str_8.compare(str_7);\n";
	std::cout << str_8.compare(str_7);
	std::cout << std::endl;

	String str_9(", My Dear Dear Dear Friend!");
	str_7.append(str_9);
	std::cout << "String str_9(\", My Dear\"); str_7.append(str_9); \n";
	str_7.print();
	std::cout << std::endl;

	String str_10(". Oh! It\'s you");
	str_7.insert(5, str_10);
	std::cout << "String str_10(\". Oh, It\'s you\"); str_7.insert(5, str_10);\n";
	str_7.print();
	std::cout << std::endl;

	String str_11(". Ah, I\'m very busy");
	str_7.replace(5, 14, str_11);
	std::cout << "String str_11(\".Ah, I\'m very busy, My Friend\"); \
		str_7.replace(5, 14, str_11);\n";
	str_7.print();
	std::cout << std::endl;

	std::cout << "str_7.find(\"very\");\n" << str_7.find("very") << std::endl;

	std::cout << "str_7.find_first_of(\"aeiouy\");\n" <<
		str_7.find_first_of("aeiouy") << std::endl;

	std::cout << "str_7.find_first_not_of(\"ABCDEFGHIKLMNOPQRSTVXYZabcdefghiklmnopqrstvxyz ., \");\n" <<
		str_7.find_first_not_of("ABCDEFGHIKLMNOPQRSTVXYZabcdefghiklmnopqrstvxyz .,") << std::endl;

	system("pause");
	return 0;
}
*/