#pragma once
#include <stdint.h>

/* class IIR-filter
Constructors:
...(float tau,float Ts)             // 1st order LP-filter in ZOH trafo
...(float tau, float Ts, float K)   // "        "          with gain K

methods:
reset(void)         // sets internal vars to zero
eval(float u)       // make one step iteration with input u
operator: (float)   // calls "eval" 

*/
class IIR_filter
{
public:
    IIR_filter(float,float);                //Construktor PT1
    IIR_filter(float,float,float,float);    //Construktor PT2
    virtual ~IIR_filter();
    float eval(float);
    float operator()(float u){
            return eval((float)u);
         }
private:
    float *B;
    float *A;
    uint8_t nb,na;
    float a0, a1, a2, b0;
    float y, Y_k1, Y_k2, U_k1, U_k2; 
};