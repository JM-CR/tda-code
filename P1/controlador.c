// See controlador.h for more information.
// Author: Gabriela Rojano
// File: controlador.c
// Date: 27/02/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "controlador.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private global variables */

static int order;
static double *initial_values;
static double *coefficients;
static double *steps;
static int iValues = 0;
static int iCoeff = 0;


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

void addInitialValue(double value) {
    // Append data
    initial_values[iValues++] = value;
}

void addCoefficient(double coef) {
    // Append data
    coefficients[iCoeff++] = -coef;
}

void addOrder(int or) {
    order = or;
    initial_values = calloc(order, sizeof(double));
    coefficients = calloc(order, sizeof(double));
}

bool makeSteps( double span, int numMuestras ) {
    // Create memory
    steps = calloc(numMuestras, sizeof(double));

    // Fill
    double value = 0.0;
    double slice = span / numMuestras;
    for ( int i = 0; i < numMuestras; ++i, value += slice )
        steps[i] = value;

    // Call model
    setSampleSize(numMuestras);
    return processData(coefficients, initial_values, order, steps);
}
