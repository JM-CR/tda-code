
// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include "controlador.h"


// -----------------------------
// Public elements
// -----------------------------

int order;
int initial_values[order];
int coefficients[order];
int steps[1000];
int iValues = 0;
int iCoeff = 0;
/* Implementation of the public functions */

void addInitialValue(int value) {
    // Append data
    initial_values[iValues] = value;
    iValues++;
}

void addCoefficient(int coef){
    coeffients[iCoeff] = coef;
    iCoeff++;
}

void addOrder(int or){
    order=or;
}

void makeSteps(int lapso, int numMuestras ){
    double v = lapso/numMuestras;
    for (int i = 0 ; i<v; i++){
        steps[i] = i;
    }

}


