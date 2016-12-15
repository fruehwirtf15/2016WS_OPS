#ifndef FUNKTION_H
#define FUNKTION_H


class Funktion
{
    //1D
public:
    double operator()(double x);
    virtual double value(double x);

};

#endif // FUNKTION_H
