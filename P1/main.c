// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 22/02/20

// ------------------------------------------
// Sspanstem and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include "vista.h"
#include "controlador.h"

int main(void) {
    // Presentation
    initialRun();

    // Aks order
    int order = askOrder();
    addOrder(order); printf("\n");

    // Ask coefficients
    char buffer[2];
    for ( int i = 0; i < order; i++ ) {
        sprintf(buffer, "%d", order - i);
        addCoefficient(askCoefficients(buffer));
    }
    printf("\n");

    // Ask initial values
    for ( int i = 0; i < order; i++ ) {
        sprintf(buffer, "%d", order - i);
        addInitialValue(askInitialValue(buffer));
    }
    printf("\n");

    // Ask number of time points
    double span = askSpan(); printf("\n");
    int samples = askSampleSize(); printf("\n");

    // Call model
    (void) makeSteps(span, samples);

    return 0;
}