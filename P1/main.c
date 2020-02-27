// Author: Hector Jair Hernandez Cortes
// File: main.c
// Date: 22/02/20

// ------------------------------------------
// Sspanstem and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include "vista.h"
#include "controlador.h"

int main(void) {
    // Call view and controller
    int order = askOrder();
    addOrder(order);

    char buffer[2];
    for ( int i = 0; i < order; i++ ) {
        sprintf(buffer, "%d", order - i);
        askCoefficients(buffer);
    }
    
    for ( int i = 0; i < order; i++ ) {
        sprintf(buffer, "%d", order - i);
        askInitialValue(buffer);
    }

    double span = askSpan();
    int samples = askSampleSize();

    // Call model
    (void) makeSteps(span, samples);

    return 0;
}