/*
	Author: reznikovkg
	GitHub: https://github.com/reznikovkg
	Email: kosrez1@yandex.ru
	GitHub Repository: https://github.com/reznikovkg/genetic-algorithm
*/

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
	/*
	 * Геттеры
	 */


	Individ getIndivid(int k)
	{
		return Individs[k];
	}

	/*
	 * Сеттеры
	 */
	void setHeart(signed int max)
	{
		for (int i = 0; i < num; i++) {
			Individs[i].setHeart(max);
		}
	}

	void setIndivid(Individ Ind, int num_Ind)
	{
		Individs[num_Ind] = Ind;
	}
	
	void setPopulation(int min, int max, int num_Individ)
	{
		for (int i = 0; i < num; i++) {
			Individs[i] = Individ(i, num_Individ);
			Individs[i].setRand(min, max);
		}
	}

	
	
	

	/*
	 * Спец. Геттеры
	 */
	//Получить особь с вероятностью из популяции
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

	//Получить всю мощьность популяции
	signed long getSumHeart()
	{
		signed long out = 0;

		for (int i = 0; i < num; i++) {
			out += Individs[i].getHeart();
		}

		return out;
	}

	//Получить максимальный фитнес у популяции (самое плохое решение)
	signed long getMaxFitness(signed int f(int, int*), int numDioph)
	{
		signed long out = 0;

		for (int i = 0; i < num; i++) {
			signed long now = Individs[i].setFintess(f, numDioph);
			if (now > out) {
				out = now;
			}
		}

		return out;
	}

	signed long getMinFitness(signed int f(int, int*), int numDioph)
	{
		signed long out = getMaxFitness(f, numDioph);
		for (int i = 0; i < num; i++) {
			signed long now = Individs[i].setFintess(f, numDioph);
			if (now < out) {
				out = now;
			}
		}

		return out;
	}


	void print()
	{
		cout << "Print population (all individs): \n";
		for (int i = 0; i < num; i++) {
			cout << Individs[i].getId() << ")\t";
			Individs[i].print();
		}
		cout << "\n";
	}

	void printByDownFitness(int maxFit)
	{
		for (int i = 0; i < num; i++) {
			if (Individs[i].getFit() < maxFit) {
				cout << "\t";
				Individs[i].print();
			}
		}
	}
	~Population() {};
};
