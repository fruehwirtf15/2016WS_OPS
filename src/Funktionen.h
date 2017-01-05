/*
 * Funktionen.h
 *
 *  Created on: 15.12.2016
 *      Author: FruehwF
 */

#ifndef FUNKTIONEN_H_
#define FUNKTIONEN_H_


//TODO Implementieren der Testfunktionen nach 8.1 Eindimensionale Funktionen Seite 42

class f1: public Funktion {
public:

	double value(double x) {
        return x * x - 1;
    }
};

class f2: public Funktion {
public:
	double value(double x) {
		// TODO Implement f2
		return 2*x * x - 1;
	} //f(x)

};
class f3: public Funktion {
public:
	double value(double x) {
		// TODO Implement f1
		return 3*x * x - 1;
	} //f(x)
};
class f4: public Funktion {
public:
	double value(double x) {
		// TODO Implement f1
		return 4*x * x - 1;
	} //f(x)

};
class f5: public Funktion {
public:
	double value(double x) {
		// TODO Implement f1
		return 5*x * x - 1;
	} //f(x)

};
class f6: public Funktion {
public:
	double value(double x) {
		// TODO Implement f6
		return 6*x * x - 1;
	} //f(x)

};

#endif /* FUNKTIONEN_H_ */
