/*
	Author: reznikovkg
	GitHub: https://github.com/reznikovkg
	Email: kosrez1@yandex.ru
	GitHub Repository: https://github.com/reznikovkg/genetic-algorithm
*/

#include <iostream>

using namespace std;

signed int Diophantine(int numDiophantine, int * x)
{
	signed int out = 0;
	for (int i = 1; i <= numDiophantine; i++)
	{
		out += i * x[i - 1];
	}
	return out;
}
