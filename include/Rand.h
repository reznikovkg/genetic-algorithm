#include <iostream>

using namespace std;

int Rand(int min, int max)
{
	return (double)(rand()) / RAND_MAX * (max - min) + min;
}

signed int RandBig(signed int min, signed int max)
{
	return (double)(rand()) / RAND_MAX * (max - min) + min;
}
