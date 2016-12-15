//============================================================================
// Name        : NotLinOpt.cpp
// Author      : Stomakhin Andrey, Fruehwirth Franz, Hanzer Daniel, Cherches Nicole, Filippovits Lukas
// Version     : 0.1
// Copyright   : 
// Description : Nichtlineare Optimierung ohne Nebenbedingungen: Eindimensionale Verfahren
//============================================================================

#include <iostream>
#include <cmath>
#include "Funktion.h"
#include "Funktionen.h"
#include "GS.h"
#include "InterfaceOptVerfahren.h"

using namespace std;

void auswerten(Funktion &f,InterfaceOptVerfahren &v, double x) {

	cout << "x-Wert: " << x << " Funktionswert: " << f.value(x) << " Min: "<< v.findMinimum(0.0,10.0,f,0.003) <<endl; // prints Test Value
}

int main() {
	f1 f;
	GS Verfahren;;
	double x = 3.3;
	auswerten(f,Verfahren,x);

	return 0;
}
