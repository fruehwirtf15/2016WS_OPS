/*
 * FB.cpp
 *
 *  Created on: 15.12.2016
 *      Author: FruehwF
 */

#include "FB.h"

namespace std {

FB::FB() {
	GetFibonacci[0] = 1;
	GetFibonacci[1] = 1;
	for (int i = 2;i<90;i++){
		GetFibonacci[i] = GetFibonacci[i-1] + GetFibonacci[i-2];
	}

}

FB::~FB() {
	// TODO Auto-generated destructor stub
}

// Abbildung der Achse von long long auf double
double FB::transform(unsigned long long fibo){
	return start + Interval * fibo;
}



double FB::findMinimum(double a, double b, Funktion &f, double epsilon,
		ofstream& myfile) {
	double lambda, f_lambda;
	double mue, f_mue;
	unsigned long long a_f, lambda_f,mue_f,b_f;

	FB::start = a;
	int Iteration = 0;
	int i = 0;
	unsigned long long fib_i = 0;
	unsigned long long  anzahlIntervalle = (unsigned long long) (1.0/epsilon);

	while (anzahlIntervalle > (fib_i = GetFibonacci[++i]));

	cout << "Iterationen: " << i << endl;
	epsilon = 1.0 / (double) fib_i;
	FB::Interval = (b - a) * epsilon;
	a_f = 0;
	b_f = fib_i;

	int k = 1;

	lambda_f = a_f + ((b_f - a_f) * GetFibonacci[i - k - 1]) / GetFibonacci[i - k + 1];
	lambda = transform(lambda_f);
	f_lambda = f.value(lambda);

	mue_f = a_f + ((b_f - a_f) * GetFibonacci[i - k]) / GetFibonacci[i - k + 1];
	mue = transform(mue_f);
	f_mue = f.value(mue);

	if (myfile.is_open()) myfile << Iteration << "  " << transform(a_f) << "  " << lambda << "  " << mue<< "  " << transform(b_f)
			<< "  " << f_lambda << "  " << f_mue << endl;
	while (k < i) {
		Iteration++;
		if (f_lambda < f_mue) {
			// alles rechts von mue faellt weg, lambda wird zu mue
			b_f = mue_f;
			mue_f = lambda_f;
			f_mue = f_lambda;
			lambda_f = a_f + ((b_f - a_f) * GetFibonacci[i - k - 1]) / GetFibonacci[i - k + 1];
			lambda = transform(lambda_f);
			f_lambda = f.value(lambda);
			k++;
		} else {
			// alles links von lambda faellt weg, mue wird zu lambda
			a_f = lambda_f;
			lambda_f = mue_f;
			f_lambda = f_mue;
			mue_f = a_f + ((b_f - a_f) * GetFibonacci[i - k]) / GetFibonacci[i - k + 1];
			mue = transform(mue_f);
			f_mue = f.value(mue);
			k++;
		}
		if (myfile.is_open()) myfile << Iteration << "  " << transform(a_f) << "  " << transform(lambda_f) << "  " << transform(mue_f)<< "  " << transform(b_f)
				<< "  " << f_lambda << "  " << f_mue << endl;
	}
	return (transform(mue_f) + transform(lambda_f)) / 2;
}

} /* namespace std */

