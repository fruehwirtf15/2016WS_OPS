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
double FB::transform(long long fibo){
	return start + Interval * fibo;
}



double FB::findMinimum(double a, double b, Funktion &f, double epsilon,
		ofstream& myfile) {
	double lambda, f_lambda;
	double mue, f_mue;
	long long a_f, lambda_f,mue_f,b_f;

	FB::Interval = (b - a) * epsilon;
	FB::start = a;
	int Iteration = 0;
	int i = 1;
	int fib_i = GetFibonacci[i];

	while ((1.0 / (fib_i)) > epsilon) {
		i++;
		fib_i = GetFibonacci[i]; //This is not an ideal solution in terms of effiency, might come back to it later.
	}
	cerr << "Iterationen: " << i << endl;

	a_f = 0;
	b_f = GetFibonacci[i];

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
		if (myfile.is_open()) myfile << Iteration << "  " << transform(a_f) << "  " << lambda << "  " << mue<< "  " << transform(b_f)
				<< "  " << f_lambda << "  " << f_mue << endl;
	}
	return (mue + lambda) / 2;
}

} /* namespace std */

