#include <iostream>
#include "String.h"

int main()
{
	char* c = new char[5];
	c[0] = 'a';
	c[1] = 'c';
	c[2] = 'a';
	c[3] = 'b';
	c[4] = '\0';
	char* c1 = new char[5];
	c1[0] = 'c';
	c1[1] = 'c';
	c1[2] = 'c';
	c1[3] = 'c';
	c1[4] = '\0';
	TString s1(c);
	TString s2(c1);
	std::cout << (s1 < s2) << std::endl;
	std::cout << s1.Find(c1) << std::endl;
	std::cout << s1.Find('b') << std::endl;
	s1.Duplication(3);
	std::cout << s1.Simv() << std::endl;
	std::cout << s1.Entering(c1) << std::endl;
	std::cout << s1.Povtor();
	s1.CountSimv();
	s1 = s2;
	for (int i = 0; i < s1.split('a'); i++)
	{
		std::cout << Split('a', s1)[i].GetStr() << std::endl;
	}
	return 0;
}