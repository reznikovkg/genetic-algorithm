/*
	Author: reznikovkg
	GitHub: https://github.com/reznikovkg
	Email: kosrez1@yandex.ru
	GitHub Repository: https://github.com/reznikovkg/genetic-algorithm
*/

#include <iostream>

using namespace std;

class Individ
{
private:
	int num;
	int id;
	int * chromosome;
	signed int fit;
	signed int heart;

public:
	Individ() {};

	Individ(int id_Individ, int num_Individ)
	{
		id = id_Individ;
		num = num_Individ;
		chromosome = new int[num];
		heart = 0;
	}
	/*
	 * Геттеры
	 */
	int getId()
	{
		return id;
	}
	int getNum()
	{
		return num;
	}
	int getChromosome(int id)
	{
		return chromosome[id];
	}
	signed int getFit()
	{
		return fit;
	}
	signed int getHeart()
	{
		return heart;
	}

	/*
	* Сеттеры
	*/
	void setRand(int min, int max)
	{
		for (int i = 0; i < num; i++) {
			chromosome[i] = Rand(min, max);
		}
	}
	
	signed int setFintess(int f(int, int*), int numDioph)
	{
		fit = abs(f(numDioph, chromosome));
		return fit;
	}

	void setHeart(signed int max)
	{
		heart = max - fit;
	}
	
	void setByParents(Individ Pm, Individ Pd, int diff)
	{
		num = Pm.getNum();
		chromosome = new int[num];

		for (int i = 0; i < diff; i++) {
			chromosome[i] = Pm.getChromosome(i);
		}
		for (int i = diff; i < num; i++) {
			chromosome[i] = Pd.getChromosome(i);
		}
	}




	void print()
	{
		for (int i = 0; i < num; i++) {
			cout << chromosome[i] << "\t";
		}

		cout << fit << "\n";
	}

	/*
	 * Мутации
	 */
	void mutationInverse() {
		int begin = Rand(0, num-1);
		int end = Rand(begin, num);
		int nowBack = 0;
		int *oldChromosome = new int[num];
		for (int i = 0; i < num; i++) {
			oldChromosome[i] = chromosome[i];
		}
		for (int i = begin; i <= end; i++) {
			chromosome[i] = oldChromosome[end - nowBack];
			nowBack++;
		}
	}

	void mutationRandomWobble() {
		int begin = Rand(0, num - 1);
		int end = Rand(begin, num);
		for (int i = begin; i <= end; i++) {
			if (chromosome[i] > 0) {
				chromosome[i] = chromosome[i] + 1;
			} else {
				chromosome[i] = chromosome[i] - 1;
			}
		}
	}

	~Individ() {};
};
