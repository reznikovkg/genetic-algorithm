#include <iostream>

using namespace std;

class Individ
{
private:
	int num;
	int id;
	signed int fit;
	signed int heart;
	int * chromosome;

public:
	Individ() {};

	Individ(int id_Individ)
	{
		id = id_Individ;
		num = 4;
		chromosome = new int[num];
		heart = 0;
	}

	void print()
	{
		for (int i = 0; i < num; i++) {
			cout << chromosome[i] << "\t";
		}
		
		cout << fit << "\n";
	}

	void setRand(int min, int max)
	{
		for (int i = 0; i < num; i++) {
			chromosome[i] = Rand(min, max);
		}
	}

	int getId()
	{
		return id;
	}

	int getChromosome(int id)
	{
		return chromosome[id - 1];
	}

	signed int getFintess(int f(int, int, int, int))
	{
		fit = abs(f(chromosome[0], chromosome[1], chromosome[2], chromosome[3]));
		return fit;
	}

	void setInverseForFintess(signed int max)
	{
		heart = max - fit;
	}
	signed int getFit()
	{
		return fit;
	}
	signed int getHeart()
	{
		return heart;
	}

	~Individ() {};
};
