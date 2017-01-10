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
#include "GS.h"
#include "Funktionen.h"


using namespace std;

void auswerten(Funktion &f, InterfaceOptVerfahren &v, double a, double b,
		double eps) {
	double x = v.findMinimum(a, b, f, eps);
	std::cout << "Min: " << x << " Funktionswert: " << f.value(x) << endl;
}


void ausgeben(Funktion &f, InterfaceOptVerfahren &v, double a, double b,
		double eps, string filename) {

	std::ofstream dataFile;
	std::ofstream cmdFile;
	try {
		system("mkdir \"data\" 2> nul");
	}
	catch (...){}
	string pngName = ".//data//" + filename + PLOT_EXT;
	filename = ".//data//" + filename + DATA_EXT;
	dataFile.open(filename);

	double x = v.findMinimum(a, b, f, eps, dataFile);

	cout << "Min: " << x << " Funktionswert: " << f.value(x) << endl; // prints Test Value
	dataFile.close();
	cout << " written to: " << filename<<endl;
// Make png cmd-File

	cmdFile.open("Cmdfile");
	cmdFile << "set terminal png size 1500,1200"<<endl;
	cmdFile << "set output '"<<pngName<<"'"<<endl;
	cmdFile<<  "set title '" << v.getName() << "'" << std::endl;
	cmdFile << "set xlabel 'Iteration'" << endl;
	cmdFile << "set grid" << endl;
	cmdFile << "plot '" << filename << "' using 2 title 'a' with lines, \\"
			<< endl;
	cmdFile << "'" << filename << "' using 3 title 'lambda' with lines, \\"
			<< endl;
	cmdFile << "'" << filename << "' using 4 title 'my' with lines, \\" << endl;
	cmdFile << "'" << filename << "' using 5 title 'b' with lines" << endl;
	cmdFile << "exit"<<endl;
	cmdFile.close();
	system("gnuplot < Cmdfile");


// Make X-Screen cmd-File
	cmdFile.open("Cmdfile");
	cmdFile<<  "set title '" << v.getName() << "'" << std::endl;
	cmdFile << "set xlabel 'Iteration'" << endl;
	cmdFile << "set grid" << endl;
	cmdFile << "plot '" << filename << "' using 2 title 'a' with lines, \\"
			<< endl;
	cmdFile << "'" << filename << "' using 3 title 'lambda' with lines, \\"
			<< endl;
	cmdFile << "'" << filename << "' using 4 title 'my' with lines, \\" << endl;
	cmdFile << "'" << filename << "' using 5 title 'b' with lines" << endl;
	cmdFile << "pause 5"<<endl;
	cmdFile.close();
	system("gnuplot < Cmdfile");

}
bool match(const std::string& s, const char * c) {
	return c && s.length() > 0 && s.length() <= std::strlen(c)
			&& s.compare(0, s.length(), c, s.length()) == 0;
}

const char helpstr[] =
		"Usage: <Methode> <Function> <Lower Bound> <Upper Bound> <Epsilon> [outputfile]\n"
				"Example: BI f1 0.5 10.5 0.0003 output\n"
				"         Bisec methode with function f1 result in ./data/output.txt and plot in ./data/output.png \n\n"
				"Methods to select\n"
				"BI ............................ Bisection method\n"
				"FB ............................ Fibonacci methode\n"
				"GS ............................ Golden ratio methode\n\n"
				"Functions to select\n"
				"f1 .................. 2x^2 + e^(-2x)\n"
				"f2 .................. (x^4)/4 - x^2 + 2x\n"
				"f3 .................. x^5 + 5x^4 + 5x^3 - 5x^2 - 6x\n"
				"f4 .................. x^4 - 16 x^2 - 1\n"
				"f5 .................. ln(|x^3 + 5x -5|)\n"
				"f6 .................. ln(|x^4 - 16 x^2 - 1|)\n"
				"quit .......................... quit program\n\n"
				"arguments surrounded by [] are optional\n";

Funktion* chooseFunction(const std::string funcmd, f1 f_1,  f2 f_2,  f3  f_3,  f4 f_4,
		 f5 f_5,  f6 f_6) {

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

	std::cout << helpstr;
	while (true) {
		string filename = "";
		Funktion* f = nullptr;
		double a = 0.0;
		double b = 10.0;
		double epsilon = 0.0004;

		std::cout << std::endl << "> ";

		std::string cmdline;
		if (!std::getline(std::cin, cmdline))
			break;

		std::istringstream cmdstream(cmdline);
		std::string cmd;

		cmdstream >> cmd;

		try {
#if defined(DEBUG)
			double time1 = 0.0, tstart;
			tstart = clock();
#endif
			if (cmd.length() == 0) {
			} else if (match(cmd, "quit")) {
				std::cout << endl;
				std::cout << cmd << "Auf Wiederschaun!" << endl;
				break;
			} else if (match(cmd, "help") || cmd == "?") {
				std::cout << helpstr;
			} else if (match(cmd, "BI") || match(cmd, "GS") || match(cmd, "FB")) {
				InterfaceOptVerfahren* verfahren = nullptr;
				if (match(cmd, "BI")){
					verfahren = &bisec;
				}
				else if (match(cmd, "GS")){
					verfahren = &gs;
				}
				else if (match(cmd, "FB")){
					verfahren = &fibo;
				}
				std::string funcmd;
				cmdstream >> funcmd;
				f = chooseFunction(funcmd, f_1, f_2, f_3, f_4, f_5, f_6);
				if (f) {
					cmdstream >> a >> b >> epsilon;
					if (a > b) swap(a,b);
					if (epsilon > (b-a) || !epsilon) epsilon = (b-a) / 1000.0;
					cmdstream >> filename;
					if (filename != "") {
						ausgeben(*f, *verfahren, a, b, epsilon, filename);
					}
					else {
						auswerten(*f, *verfahren, a, b, epsilon);
					}
				}
				else {
					std::cout << cmd <<" " << funcmd << "? try 'help'";
				}

			} else {
				std::cout << cmd << "? try 'help'";
			}
#if defined(DEBUG)
			time1 += clock() - tstart;     // end
			time1 = time1 / CLOCKS_PER_SEC;// rescale to seconds
			std::cout << "  time for "<<cmd <<" = " << time1 << " sec." << std::endl;
			std::cerr<<epsilon<<" "<< time1 << std::endl;
#endif
		} catch (CalculationException& e) {
			std::cout << "catched FunctionException \"" << e.what() << "\"";

		} catch (std::exception& e) {
			std::cout << "catched std::exception \"" << e.what() << "\"";
		} catch (...) {
			std::cout << "OOPS! - catched something else";
		}
	}

	return 0;
}
