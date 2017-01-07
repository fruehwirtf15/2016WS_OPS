/*
 * Funktionen.h
 *
 *  Created on: 15.12.2016
 *      Author: FruehwF
 */

#ifndef FUNKTIONEN_H_
#define FUNKTIONEN_H_

#include <time.h>
#include <cmath>
//TODO Implementieren der Testfunktionen nach 8.1 Eindimensionale Funktionen Seite 42

void sleepcp(int milliseconds) // cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end)
    {
    }
}

class f1: public Funktion {
public:

	double value(double x) {
		//sleepcp(30);
        return 2*pow(x,2) + exp(-2*x);
    }
};

class f2: public Funktion {
public:
	double value(double x) {
		// TODO Implement f2
		return (pow(x,4)/4) - pow(x,2) + 2*x;
	} //f(x)

};
class f3: public Funktion {
public:
	double value(double x) {
		// TODO Implement f1
		return pow(x,5) + 5*pow(x,4) + 5*pow(x,3) - 5*pow(x,2) - 6*x;
	} //f(x)
};
class f4: public Funktion {
public:
	double value(double x) {
		// TODO Implement f1
		return pow(x,4) - 16*pow(x,2) - 1;
	} //f(x)

};
class f5: public Funktion {
public:
	double value(double x) {
		// TODO Implement f1
		return log(abs(pow(x,3) + 5*x - 5));
	} //f(x)

};
class f6: public Funktion {
public:
	double value(double x) {
		// TODO Implement f6
		return log(abs(pow(x,4) - 16*pow(x,2) - 1));
	} //f(x)

};

#endif /* FUNKTIONEN_H_ */
