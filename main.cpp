/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <cstdint>
#include <stdint.h>

#include "IIR_filter.h"

DigitalOut led(LED1);

// main program
static BufferedSerial serial_port(USBTX, USBRX);

int main()
{    serial_port.set_baud(115200);
    serial_port.set_format(
        /* bits */ 8,
        /* parity */ BufferedSerial::None,
        /* stop bit */ 1);
    serial_port.set_blocking(false);
    printf("Start loop\n");

    const uint16_t N = 100;
    float u[N]; 
    float y[N];
    IIR_filter LP(2.0,15.0,0.3,0.01);                //Initiation Filter
    for(uint16_t k = 0; k<N;k++)
    u[k] = 1;
    for(uint16_t k = 0; k<N;k++)
    y[k] = LP(u[k]);                        //Filter
    for(uint16_t k = 0; k<N;k++)
    printf("%2.3f %2.3f\r\n",u[k],y[k]);

    while(1) 
    ;    
    

}
