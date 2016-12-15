/*
 * BI.h
 *
 *  Created on: 15.12.2016
 *      Author: FruehwF
 */

#ifndef BI_H_
#define BI_H_

#include "InterfaceOptVerfahren.h"

namespace std {

class BI: public InterfaceOptVerfahren {
public:
	BI();
	virtual ~BI();
	virtual double findMinimum(double a, double b, Funktion &f, double epsilon)
			override;
	virtual void makeGnuPlotFile(double a, double b, Funktion &f,
			double epsilon, string fileName) override;
};

} /* namespace std */

#endif /* BI_H_ */
