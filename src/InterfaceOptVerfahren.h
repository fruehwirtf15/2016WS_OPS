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
#include <iostream>
#include <fstream>

namespace std {

class InterfaceOptVerfahren {
public:
	InterfaceOptVerfahren();
	virtual ~InterfaceOptVerfahren();
	virtual double findMinimum(double a, double b, Funktion &f, double epsilon){
		ofstream myfile;
		myfile.open("dummy");
	    myfile.close();
		return findMinimum( a, b, f, epsilon, myfile);
	};
	virtual double findMinimum(double a, double b, Funktion &f, double epsilon, ofstream& myfile) = 0;
	virtual string getName() = 0;
};

} /* namespace std */

#endif /* INTERFACEOPTVERFAHREN_H_ */
