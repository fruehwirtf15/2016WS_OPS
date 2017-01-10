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
	using InterfaceOptVerfahren::findMinimum;
	virtual double findMinimum(double a, double b, Funktion &f,
			double epsilon, ofstream& myfile) override;
	virtual string getName() override {return "Bisektions Verfahren";} ;
};

} /* namespace std */

#endif /* BI_H_ */
