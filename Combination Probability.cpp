// Combination Probability.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>

using namespace std;


double factorial(double num) {
	double sum = 1;
	for (int i = 1; i <= num; i++) {
		sum *= i;
	}
	return sum;
}

double CombinationCalculator(double total, double target) {
	double num = factorial(total) / (factorial(target) * factorial(total - target));
	return num;
}

double ProbabilityEquation(double total, double probability, double target) {
	double num1 = pow(probability, target);
	double num2 = pow((1.0 - probability), (total - target));
	double num3 = CombinationCalculator(total, target) * num1 * num2;
	return num3;
}

double FindLessThan(double total, double probability, double target) {
	double totalProb = 0;
	for (int i = 0; i < target; i++) {
		totalProb += ProbabilityEquation(total, probability, i);
	}
	return totalProb;
}

double FindMoreThan(double total, double probability, double target) {
	double totalProb = 0;
	for (int i = total; i > target; i--) {
		totalProb += ProbabilityEquation(total, probability, i);
	}
	return totalProb;
}




int main()
{
	double total;
	double probability;
	double target;

	cout << "Welcome to the probability calculator" << endl << endl;
	while (true) {
		cout << "Input total number of elements: ";
		if (cin >> total && total > 0) {
			break;
		}
		else {
			cout << endl << "Invalid Input, please enter an integer greater than 0";
		}
	}
	while (true) {
		cout << "Input probability: ";
		if (cin >> probability && probability <= 1 && probability >= 0) {
			break;
		}
		else {
			cout << endl << "Invalid Input, please enter a decimal between 0 and 1";
		}
	}
	while (true) {
		cout << "Input target integer: ";
		if (cin >> target && target <= total && target > 0) {
			break;
		}
		else {
			cout << endl << "Invalid Input, please enter an integer smaller than total and greater than 0";
		}
	}
	

	cout << endl << endl << "More than " << target << " events: " << FindMoreThan(total, probability, target);
	cout << endl << "Less than " << target << " events: " << FindLessThan(total, probability, target);
	cout << endl << "Exactly " << target << " events: " << ProbabilityEquation(total, probability, target);
	
}

