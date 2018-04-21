#include <iostream>

using namespace std;

class Population
{
private:
	int num;
	Individ * Individs;

public:
	Population() {};

	Population(int num_individ)
	{
		num = num_individ;
		Individs = new Individ[num];
	}

	void print()
	{
		cout << "Print population (all individs): \n";
		for (int i = 0; i < num; i++) {
			cout << Individs[i].getId() <<")\t";
			Individs[i].print();
		}
		cout << "\n";
	}
	
	void setPopulation(int min, int max)
	{
		for (int i = 0; i < num; i++) {
			Individs[i] = Individ(i);
			Individs[i].setRand(min, max);
		}
	}

	Individ getIndivid(int k)
	{
		return Individs[k];
	}

	signed long getSumHeart(int f(int, int, int, int))
	{
		signed long out = 0;

		for (int i = 0; i < num; i++) {
			out += Individs[i].getHeart();
		}

		return out;
	}

	signed long getMaxFitness(int f(int, int, int, int))
	{
		signed long out = 0;

		for (int i = 0; i < num; i++) {
			signed long now = abs(Individs[i].getFintess(f));
			if (now > out) {
				out = now;
			}
		}

		return out;
	}


	void setInverseFitness(signed int max)
	{
		for (int i = 0; i < num; i++) {
			Individs[i].setInverseForFintess(max);
		}
	}
	
	Individ getIndividByHeart(signed int value)
	{
		signed int sum = 0;
		int out = 0;
		for (int i = 0; i < num; i++) {
			sum += Individs[i].getHeart();
			if (sum > value) {
				out = Individs[i].getId();
				break;
			}
		}
		return Individs[out];
	}

	~Population() {};
};
