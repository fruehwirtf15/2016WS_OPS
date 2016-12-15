/*
 * GS.h
 *
 *  Created on: 15.12.2016
 *      Author: FruehwF
 */

#ifndef GS_H_
#define GS_H_

#include "InterfaceOptVerfahren.h"
#include "Funktionen.h"

namespace std {

class GS: public InterfaceOptVerfahren {
public:
	GS();
	virtual ~GS();
	virtual double findMinimum(double a, double b, Funktion &f, double epsilon) override;
	virtual void makeGnuPlotFile(double a, double b, Funktion &f, double epsilon, string  fileName) override;
};

} /* namespace std */



#endif /* GS_H_ */
