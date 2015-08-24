#include <stdio.h>

const double er = 0.001;

typedef double(*doubleFunc)(double) ;

double test(double a, double b, doubleFunc f ) {
    double c;
    while ((b-a)/2 > er) {
        c = (a+b)/2;
        if (f(c) ==0) {
            break;
        }
        if (f(a)*f(c) < 0) {
            b = c;
        } else{
            a = c;
        }
    }
    return (a+b)/2;
}
