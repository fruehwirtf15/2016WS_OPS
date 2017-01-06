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
	long long GetFibonacci[90];
	double Interval = 1.0;
	double start = 0.0;
	double transform(long long fibo);
public:
	FB();
	virtual ~FB();
	virtual double findMinimum(double a, double b, Funktion &f, double epsilon)
			override;
	virtual void makeGnuPlotFile(double a, double b, Funktion &f,
			double epsilon, ofstream& myfile) override;
};

} /* namespace std */

#endif /* FB_H_ */
