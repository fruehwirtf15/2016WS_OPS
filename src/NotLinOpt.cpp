//============================================================================
// Name        : NotLinOpt.cpp
// Author      : Stomakhin Andrey, Fruehwirth Franz, Hanzer Daniel, Cherches Nicole, Filippovits Lukas
// Version     : 0.1
// Copyright   : 
// Description : Nichtlineare Optimierung ohne Nebenbedingungen: Eindimensionale Verfahren
//============================================================================

#include <exception>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>

#include "BI.h"
#include "FB.h"
#include "Funktionen.h"
#include "GS.h"

using namespace std;

void auswerten(Funktion &f, InterfaceOptVerfahren &v, double x, double a, double b, double eps) {

	cout << "x-Wert: " << x << " Funktionswert: " << f.value(x) << " Min: "
			<< v.findMinimum(a, b, f, eps) << endl; // prints Test Value
}
bool match(const std::string& s, const char * c) {
	return c && s.length() > 0 && s.length() <= std::strlen(c)
			&& s.compare(0, s.length(), c, s.length()) == 0;
}

const char helpstr[] = "Usage: <Methode> <Function> <Lower Bound> <Upper Bound> <Epsilon>\n"
		"Example: BI f1 0.5 10.5 0.0003\n"
		"Methode to select\n"
		"BI ............................ Bisection method\n"
		"FB ............................ Fibonacci methode\n"
		"GS ............................ Golden ratio methode\n"
		"Functions to select\n"
		"f1 .................. 2x^2 + e^(-2x)\n"
		"f2 .................. (x^4)/4 - x^2 + 2x\n"
		"f3 .................. x^5 + 5x^4 + 5x^3 - 5x^2 - 6x\n"
		"f4 .................. x^4 - 16 x^2 - 1\n"
		"f5 .................. ln(|x^3 + 5x -5|)\n"
		"f6 .................. ln(|x^4 - 16 x^2 - 1|)\n"
		"quit .......................... quit program\n\n"
		"arguments surrounded by [] are optional\n";

Funktion* chooseFunction(std::string funcmd, f1 f_1, f2 f_2, f3 f_3, f4 f_4,
		f5 f_5, f6 f_6) {

	if (funcmd.length() == 0) {
	} else if (match(funcmd, "f1")) {
		return &f_1;
	} else if (match(funcmd, "f2")) {
		return &f_2;
	} else if (match(funcmd, "f3")) {
		return &f_3;
	} else if (match(funcmd, "f4")) {
		return &f_4;
	} else if (match(funcmd, "f5")) {
		return &f_5;
	} else if (match(funcmd, "f6")) {
		return &f_6;
	}
	return nullptr;
}

int main() {
	f1 f_1;
	f2 f_2;
	f3 f_3;
	f4 f_4;
	f5 f_5;
	f6 f_6;

	BI bisec;
	FB fibo;
	GS gs;
	Funktion* f;
	double x = 3.3;
	double a = 0.0;
	double b = 10.0;
	double epsilon = 0.0004;

	std::cout << helpstr;
	while (true) {
		f = nullptr;

		std::cout << std::endl << "> ";

		std::string cmdline;
		if (!std::getline(std::cin, cmdline))
			break;

		std::istringstream cmdstream(cmdline);
		std::string cmd;

		cmdstream >> cmd;

		try {
			if (cmd.length() == 0) {
			} else if (match(cmd, "quit")) {
				std::cout << cmd << "Auf Wiederschaun!" << endl;
				break;
			} else if (match(cmd, "help") || cmd == "?") {
				std::cout << helpstr;
			} else if (match(cmd, "BI")) {
				std::string funcmd;
				cmdstream >> funcmd;
				f = chooseFunction(funcmd, f_1, f_2, f_3, f_4, f_5, f_6);

				if (f)
					cmdstream >> a >> b >> epsilon;
					auswerten(*f, bisec, x, a , b , epsilon);

			} else if (match(cmd, "FB")) {
				std::string funcmd;
				cmdstream >> funcmd;
				f = chooseFunction(funcmd, f_1, f_2, f_3, f_4, f_5, f_6);
				if (f)
					cmdstream >> a >> b >> epsilon;
					auswerten(*f, fibo, x, a , b , epsilon);
			} else if (match(cmd, "GS")) {
				std::string funcmd;
				cmdstream >> funcmd;
				cmdstream >> a >> b >> epsilon;
				f = chooseFunction(funcmd, f_1, f_2, f_3, f_4, f_5, f_6);
				if (f)
					auswerten(*f, gs, x, a , b , epsilon);
			} else {
				std::cout << cmd << "? try 'help'";
			}

		} catch (CalculationException& e) {
			std::cout << "catched ContainerException \"" << e.what() << "\"";

		} catch (std::exception& e) {
			std::cout << "catched std::exception \"" << e.what() << "\"";
		} catch (...) {
			std::cout << "OOPS! - catched something else";
		}
	}


	return 0;
}
