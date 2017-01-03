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
	double goldeneRatio = (sqrt(5)-1)/2;
	double interval = (a+b) * epsilon;
	double lambda;
	double mue;
	while ((a+b) >= interval) {
		lambda = a + (1 - goldeneRatio) * (b - a);
		mue = a + goldeneRatio * (b - a);
		if (f.value(lambda) < f.value(mue)) {
			b = mue;
		}
		else a = lambda;
	}

	return 0.0;
}

void GS::makeGnuPlotFile(double a, double b, Funktion &f, double epsilon, string fileName) {
	//TODO Ausgabe des Optimierungsverlaufs in eine Datei.
}

} /* namespace std */


