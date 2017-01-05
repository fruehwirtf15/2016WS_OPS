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
	return f.value((a+b)/2.0);
}

void BI::makeGnuPlotFile(double a, double b, Funktion &f, double epsilon, ofstream& file) {
	//TODO Ausgabe des Optimierungsverlaufs in eine Datei.
}

} /* namespace std */


