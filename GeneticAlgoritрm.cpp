/*
	Author: reznikovkg
	GitHub: https://github.com/reznikovkg
	Email: kosrez1@yandex.ru
	GitHub Repository: https://github.com/reznikovkg/genetic-algorithm
*/

#include "stdafx.h"
#include <iostream>
#include "include/Rand.h"

#include "include/Diophantine.h"

#include "include/Individ.h"
#include "include/Population.h"

using namespace std;

int minNumEv = -200;
int maxNumEv = 200;

int sizePopulation = 100;
int numGeneration = 5000;

int numDiophantine = 12;

int fitDown = 1;

int main()
{
	Population myPopulation(sizePopulation); //Создание популяции с фиксированным количеством особей
	myPopulation.setPopulation(minNumEv, maxNumEv, numDiophantine); //Сеттер рандомных значений мин/макс
	//myPopulation.print(); //Печать популяции

	signed int maxFitnes = myPopulation.getMaxFitness(Diophantine, numDiophantine); //Получение максимально "плохой" особи через фитнес
	//cout << "Max Fitness: " << maxFitnes << "\n"; //Печать

	myPopulation.setHeart(maxFitnes); //Сеттер "мощности" особи для вероятности и её дальнейшего взаимодействия

	signed int sumHeart = myPopulation.getSumHeart(); //Получение полной суммы мощности для вычисления вероятности
	//cout << "Sum Heart: " << sumHeart << "\n";


	myPopulation.print(); //Печать популяции с начальными данными
	for (int i = 0; i < numGeneration; i++) {
		signed int firstParentV = RandBig(0, sumHeart); //Получение значения первого рандомного родителя с учетом мощности и вероятности
		signed int secondParentV = RandBig(0, sumHeart); //Получение значения второго рандомного родителя с учетом мощности и вероятности

		//cout << "Parent 1: " << firstParentV << "  Parent 2: " << secondParentV << "\n"; //печать номера-мощности родителя

		Individ firstParent = Individ();
		Individ secondParent = Individ();

		firstParent = myPopulation.getIndividByHeart(firstParentV); //Выбор первого родителя по значению вероятности
		secondParent = myPopulation.getIndividByHeart(secondParentV); //Выбор второго родителя по значению вероятности
		//firstParent.print(); secondParent.print(); //печать родителей

		int firstParentId = firstParent.getId(); // получение id первого родителя
		int secondParentId = secondParent.getId(); // получение id второго родителя

		Individ firstChild = Individ(); //Регистрация первого потомка
		Individ secondChild = Individ(); //Регистрация второго потомка

		int diff = Rand(0, numDiophantine); // Получение разбиение особи

		firstChild.setByParents(firstParent, secondParent, diff); //Селекция первого потомка
		secondChild.setByParents(secondParent, firstParent, diff); //Селекция второго потомка
		//firstChild.print(); secondChild.print(); //печать потомков

		firstChild.mutationInverse();
		secondChild.mutationRandomWobble();

		firstChild.setFintess(Diophantine, numDiophantine); //Сеттеры фитнес для первого помомка
		secondChild.setFintess(Diophantine, numDiophantine);  //Сеттеры фитнес для второго помомка

		Individ nowFamily[4];
		
		nowFamily[0] = firstParent;
		nowFamily[1] = secondParent;
		nowFamily[2] = firstChild;
		nowFamily[3] = secondChild;

		int firstInFamily = 0; int fitForFamily1 = maxFitnes;
		int secondInFamily = 1; int fitForFamily2 = maxFitnes;


		//Получение самых "мощных" из "семьи"
		for (int j = 0; j < 4; j++) {
			if ((nowFamily[j].getFit() < fitForFamily1) && (firstInFamily != j)) {
				if ((fitForFamily1 < fitForFamily2)&&(firstInFamily!= secondInFamily)) {
					fitForFamily2 = fitForFamily1; secondInFamily = firstInFamily;
				}
				fitForFamily1 = nowFamily[j].getFit(); firstInFamily = j;
			} else {
				if ((nowFamily[j].getFit() < fitForFamily2)&&(secondInFamily != j)) {
					fitForFamily2 = nowFamily[j].getFit(); secondInFamily = j;
				}
			}
		}

		//замена исходных особей на "мощных"
		myPopulation.setIndivid(nowFamily[firstInFamily], nowFamily[firstInFamily].getId());
		myPopulation.setIndivid(nowFamily[secondInFamily], nowFamily[secondInFamily].getId());


		maxFitnes = myPopulation.getMaxFitness(Diophantine, numDiophantine); //Получение максимально "плохой" особи через фитнес
		//cout << "Max Fitness: " << maxFitnes << "\n"; //Печать

		myPopulation.setHeart(maxFitnes); //Сеттер "мощности" особи для вероятности и её дальнейшего взаимодействия

		sumHeart = myPopulation.getSumHeart(); //Получение полной суммы мощности для вычисления вероятности
		//cout << "Sum Heart: " << sumHeart << "\n";

		if (myPopulation.getMinFitness(Diophantine, numDiophantine) < fitDown) {
			
			cout << i << ": AGE \n";
			myPopulation.printByDownFitness(fitDown);
			cout << "\n\n";
		}

	}

	system("pause");
    return 0;
}
