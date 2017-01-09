/*
 * GS.cpp
 *
 *  Created on: 15.12.2016
 *      Author: FruehwF
 */

#include "GS.h"
#include <cmath>

namespace std {

GS::GS() {
	// TODO Auto-generated constructor stub

}

GS::~GS() {
	// TODO Auto-generated destructor stub
}

double GS::findMinimum(double a, double b, Funktion &f, double epsilon) {
	double goldenRatio = (sqrt(5) - 1) / 2;
	double interval = (b - a) * epsilon;
	double lambda, f_lambda;
	double mue, f_mue;

	lambda = a + (1 - goldenRatio) * (b - a);
	f_lambda = f.value(lambda);
	mue = a + goldenRatio * (b - a);
	f_mue = f.value(mue);

	while ((b - a) > interval) {
		if (f_lambda < f_mue) {
			b = mue;
			mue = lambda;
			f_mue = f_lambda;
			lambda = a + (1 - goldenRatio) * (b - a);
			f_lambda = f.value(lambda);
		} else {
			a = lambda;
			lambda = mue;
			f_lambda = f_mue;
			mue = a + goldenRatio * (b - a);
			f_mue = f.value(mue);
		}
	}

	return (lambda + mue) / 2;
}

void GS::makeGnuPlotFile(double a, double b, Funktion &f, double epsilon,
		ofstream& myfile) {
	// Ausgabe des Optimierungsverlaufs in eine Datei.
	double goldenRatio = (sqrt(5) - 1) / 2;
	double interval = (b - a) * epsilon;
	double lambda, f_lambda;
	double mue, f_mue;
	int Iteration = 0;

	lambda = a + (1 - goldenRatio) * (b - a);
	f_lambda = f.value(lambda);
	mue = a + goldenRatio * (b - a);
	f_mue = f.value(mue);

	while ((b - a) > interval) {
		myfile<<Iteration<<"  "<<a<<"  "<<lambda<<"  "<<mue<<"  "<<b<<"  "<<f_lambda<<"  "<<f_mue<<endl;
		Iteration++;
		if (f_lambda < f_mue) {
			b = mue;
			mue = lambda;
			f_mue = f_lambda;
			lambda = a + (1 - goldenRatio) * (b - a);
			f_lambda = f.value(lambda);
		} else {
			a = lambda;
			lambda = mue;
			f_lambda = f_mue;
			mue = a + goldenRatio * (b - a);
			f_mue = f.value(mue);
		}
	// Iteration;a;lambda;mue;b;f_lambda;f_mue
	}
	myfile<<Iteration<<"  "<<a<<"  "<<lambda<<"  "<<mue<<"  "<<b<<"  "<<f_lambda<<"  "<<f_mue<<endl;
}

} /* namespace std */

