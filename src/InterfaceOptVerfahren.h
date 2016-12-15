/*
 * InterfaceOptVerfahren.h
 *
 *  Created on: 15.12.2016
 *      Author: FruehwF
 */

#ifndef INTERFACEOPTVERFAHREN_H_
#define INTERFACEOPTVERFAHREN_H_
#include <string>
#include "Funktion.h"

namespace std {

class InterfaceOptVerfahren {
public:
	InterfaceOptVerfahren();
	virtual ~InterfaceOptVerfahren();
	virtual double findMinimum(double a, double b, Funktion &f, double epsilon) = 0;
	virtual void makeGnuPlotFile(double a, double b, Funktion &f, double epsilon, string  fileName) = 0;
};

} /* namespace std */

#endif /* INTERFACEOPTVERFAHREN_H_ */
