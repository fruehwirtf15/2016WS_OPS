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
public:
	FB();
	virtual ~FB();
	virtual double findMinimum(double a, double b, Funktion &f, double epsilon)
			override;
	virtual void makeGnuPlotFile(double a, double b, Funktion &f,
			double epsilon, string fileName) override;
};

} /* namespace std */

#endif /* FB_H_ */
