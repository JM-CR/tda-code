
// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include "controlador.h"
#include "model.h"

// -----------------------------
// Private elements
// -----------------------------

/* Private global variables */

static int order;
static int initial_values[order];
static int coefficients[order];
static int steps[1000];
static int iValues = 0;
static int iCoeff = 0;
/* Implementation of the public functions */

void addInitialValue(int value) {
    // Append data
    initial_values[iValues] = value;
    iValues++;
}

void addCoefficient(int coef){
    coefficients[iCoeff] = coef;
    iCoeff++;
}

void addOrder(int or){
    order=or;
}

bool makeSteps(double lapso, double numMuestras ){
    double v = lapso/numMuestras;
    for (int i = 0 ; i<v; i++){
        steps[i] = i;
    }
    int muestra = (int)numMuestras;
    setSampleSize(muestra);
    return processData(coefficients,initial_values,order,v)
}


