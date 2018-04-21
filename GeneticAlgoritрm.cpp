// GeneticAlgoritрm.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "include/Rand.h"

#include "include/Individ.h"
#include "include/Population.h"

using namespace std;

int Evolution(int a, int b, int c, int d)
{
	return a + 2 * b + 3 * c + 4 * d;
}

int minNumEv = -50;
int maxNumEv = 50;

int sizePopulation = 5;

int numGeneration = 10;

int main()
{
	Population myPopulation(sizePopulation); //Создание популяции с фиксированным количеством особей
	myPopulation.setPopulation(minNumEv, maxNumEv); //Сеттер рандомных значений мин/макс
	//myPopulation.print(); //Печать популяции

	signed int maxFitnes = myPopulation.getMaxFitness(Evolution); //Получение максимально "плохой" особи через фитнес
	//cout << "Max Fitness: " << maxFitnes << "\n"; //Печать

	myPopulation.setInverseFitness(maxFitnes); //Сеттер "мощности" особи для вероятности и её дальнейшего взаимодействия

	signed int sumHeart = myPopulation.getSumHeart(Evolution); //Получение полной суммы мощности для вычисления вероятности
	//cout << "Sum Heart: " << myPopulation.getSumHeart(Evolution) << "\n";


	//myPopulation.print(); //Печать популяции
	for (int i = 0; i < numGeneration; i++) {
		signed int firstParentV = RandBig(0, sumHeart); //Получение значения первого рандомного родителя с учетом мощности и вероятности
		signed int secondParentV = RandBig(0, sumHeart); //Получение значения второго рандомного родителя с учетом мощности и вероятности

		//cout << "Parent 1: " << firstParentV << "  Parent 2: " << secondParentV << "\n"; //печать номера-мощности родителя

		Individ firstParent = Individ();
		Individ secondParent = Individ();

		firstParent = myPopulation.getIndividByHeart(firstParentV); //Выбор первого родителя по значению вероятности
		secondParent = myPopulation.getIndividByHeart(secondParentV); //Выбор второго родителя по значению вероятности
		//firstParent.print(); secondParent.print(); //печать родителей

		int firstParentId = firstParent.getId();
		int secondParentId = secondParent.getId();

	}

	system("pause");
    return 0;
}
