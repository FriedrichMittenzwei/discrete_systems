#include "IIR_filter.h"

// constructors
IIR_filter::IIR_filter(float tau,float Ts)      //Initialisierung Construktor PT1
{
   this -> a0 = -tau/(tau+Ts);
   this -> b0 = Ts/(tau+Ts);
   this -> Y_k1 = 0;
}
IIR_filter::IIR_filter(float k,float wb,float D, float Ts)      //Initialisierung Construktor PT2
{
    this -> a0 = 1 + wb*wb * Ts*Ts - 2*D * wb * Ts;
    this -> a1 = 2*D * wb * Ts - 2;
    this -> a2 = 1;
    this -> b0 = wb*wb * Ts*Ts * k;

    this -> Y_k1 = Y_k2 = 0;
    this -> U_k1 = U_k2 = 0;
}

// Methods:
float IIR_filter::eval(float u)
{
    //PT1
    //float Y = -a0*Y_k1 + b0*u;
    //Y_k1 = Y;

    //PT2
    float Y = -a0*Y_k2 - a1*Y_k1 + b0*U_k2;
    Y_k2 = Y_k1;
    Y_k1 = Y;
    U_k2 = U_k1;
    U_k1 = u;
    
    return Y;       // this has to be modified!!!
}


// Deconstructor
IIR_filter::~IIR_filter() {} 