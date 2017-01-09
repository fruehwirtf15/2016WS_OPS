/*
 * BI.cpp
 *
 *  Created on: 15.12.2016
 *      Author: FruehwF
 */

#include "BI.h"

namespace std {

BI::BI() {
	// TODO Auto-generated constructor stub

}

BI::~BI() {
	// TODO Auto-generated destructor stub
}

double BI::findMinimum(double a, double b, Funktion &f, double epsilon) {
	double Ratio = 2.0 / 3.0;
	double interval = (b - a) * epsilon;
	double lambda, f_lambda;
	double mue, f_mue;

	lambda = a + (1 - Ratio) * (b - a);
	f_lambda = f.value(lambda);
	mue = a + Ratio * (b - a);
	f_mue = f.value(mue);

	while ((b - a) > interval) {
		if (f_lambda < f_mue) {
			b = mue;
		} else {
			a = lambda;
		}
		mue = a + Ratio * (b - a);
		f_mue = f.value(mue);
		lambda = a + (1 - Ratio) * (b - a);
		f_lambda = f.value(lambda);
	}

	return (mue + lambda) / 2;
}

void BI::makeGnuPlotFile(double a, double b, Funktion &f, double epsilon, ofstream& myfile) {
	// Ausgabe des Optimierungsverlaufs in eine Datei.
	double Ratio = 2.0 / 3.0;
	double interval = (b - a) * epsilon;
	double lambda, f_lambda;
	double mue, f_mue;
	int Iteration = 0;

	lambda = a + (1 - Ratio) * (b - a);
	f_lambda = f.value(lambda);
	mue = a + Ratio * (b - a);
	f_mue = f.value(mue);

	while ((b - a) > interval) {
		myfile<<Iteration<<"  "<<a<<"  "<<lambda<<"  "<<mue<<"  "<<b<<"  "<<f_lambda<<"  "<<f_mue<<endl;
		Iteration++;
		if (f_lambda < f_mue) {
			b = mue;
		} else {
			a = lambda;
		}
		mue = a + Ratio * (b - a);
		f_mue = f.value(mue);
		lambda = a + (1 - Ratio) * (b - a);
		f_lambda = f.value(lambda);
	}
	myfile<<Iteration<<"  "<<a<<"  "<<lambda<<"  "<<mue<<"  "<<b<<"  "<<f_lambda<<"  "<<f_mue<<endl;
}

} /* namespace std */


