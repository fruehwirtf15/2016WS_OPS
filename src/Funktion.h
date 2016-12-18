#ifndef FUNKTION_H
#define FUNKTION_H

class CalculationException: public std::exception {
public:
	virtual const char* what() const noexcept override = 0;
};

class Funktion
{
    //1D
public:
    double operator()(double x);
    virtual double value(double x);

};

#endif // FUNKTION_H
