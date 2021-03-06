/*
 * FB.h
 *
 *  Created on: 15.12.2016
 *      Author: FruehwF
 */

#ifndef FB_H_
#define FB_H_

#include "InterfaceOptVerfahren.h"

namespace std {

class FB: public InterfaceOptVerfahren {
	unsigned long long GetFibonacci[90];
	double Interval = 1.0;
	double start = 0.0;
	double transform(unsigned long long fibo);
public:
	FB();
	virtual ~FB();
	using InterfaceOptVerfahren::findMinimum;
	virtual double findMinimum(double a, double b, Funktion &f,
			double epsilon, ofstream& myfile) override;
	virtual string getName() override {return "Fibonacci Verfahren";} ;
};

} /* namespace std */

#endif /* FB_H_ */
