#include <iostream>
#include "splitStr.h"

void print(std::vector<std::string> x) 
{
	for (size_t i = 0; i < x.size(); i++)
		std::cout << x.at(i) << std::endl;
}
int main() {
	std::vector<std::string> test;
	splitStr(test, "test1<>Test 2<>test_ 3", "<>");
	print(test);
	splitStr(test, "test 4!,Test 5?,'TeST _6_'", ",");
	print(test);
}
