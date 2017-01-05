/*
 * FB.cpp
 *
 *  Created on: 15.12.2016
 *      Author: FruehwF
 */

#include "FB.h"

namespace std {

FB::FB() {
	// TODO Auto-generated constructor stub

}

FB::~FB() {
	// TODO Auto-generated destructor stub
}

int GetFibonacci(int position) //Returns Fibonacci Number of the given Position.
		{
	int FibonacciNumber = 1;
	int LastFibonacci = 1;
	for (int i = 0; i <= position; i++) {
		if (i == 0) {
			FibonacciNumber = 1;
			LastFibonacci = 1;
		} else {
			int help = FibonacciNumber;
			FibonacciNumber = FibonacciNumber + LastFibonacci;
			LastFibonacci = help;
		}
	}
	return FibonacciNumber;

}

double FB::findMinimum(double a, double b, Funktion &f, double epsilon) {
	double lambda;
	double mue;
	//double interval = (b - a) * epsilon;
	int i = 1;
	int fib_i = GetFibonacci(i);
	while ((1.0/(fib_i)) > epsilon){
		i++;
		fib_i = GetFibonacci(i); //This is not an ideal solution in terms of effiency, might come back to it later.
	}
	cerr << "Iterationen: " << i << endl;
	int k = 1;
	mue = a + (b - a) * (GetFibonacci(i - k - 1) / GetFibonacci(i - k + 1));
	lambda = a + (b - a) * (GetFibonacci(i - k) / GetFibonacci(i - k + 1));
	while (i > 0) {
		if (f.value(lambda) < f.value(mue)) {
			cerr << "looking below " << f.value(lambda) << " with lambda at" << lambda << endl;
			b = mue;
			mue = lambda;
			k++;
			i--;
			lambda = a + (b - a) * (GetFibonacci(i - k) / GetFibonacci(i - k + 1));
		} else {
			cerr << "looking above " << f.value(mue) << " with mue at" << mue << endl;
			a = lambda;
			lambda = mue;
			k++;
			i--;
			mue = a + (b - a) * (GetFibonacci(i - k - 1)/ GetFibonacci(i - k + 1));
		}

	}
	return (lambda - mue) / 2;
}

void FB::makeGnuPlotFile(double a, double b, Funktion &f, double epsilon,
		ofstream& file) {
//TODO Ausgabe des Optimierungsverlaufs in eine Datei.
}

} /* namespace std */

