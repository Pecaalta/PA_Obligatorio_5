#ifndef FECHA_H
#define FECHA_H

#include "string"
#include "string.h"
using namespace std;

class Fecha {
public:
    int gets();
    void sets(int _s);
    int getm();
    void setm(int _m);
    int geth();
    void seth(int _h);
    int getD();
    void setD(int _D);
    int getM();
    void setM(int _M);
    int getA();
    void setA(int _A);
    void Actual();
    string imprimeFecha();
    // Constructores y Destructores
    Fecha(int _s, int _m, int _h, int _D, int _M, int _A);
    Fecha();
    ~Fecha();
private:
    int s;
    int m;
    int h;
    int D;
    int M;
    int A;
};



#endif /* FECHA_H */

