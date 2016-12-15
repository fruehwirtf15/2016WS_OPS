#include <iostream>
#include <stdexcept>

#include "Funktion.h"


const std::string warnung = "nicht implementiert";

double Funktion::operator()(double x) {
    return this->value(x);
}
double Funktion::value(double x) { throw std::runtime_error("f.value(x) = f(x) " + warnung); }



