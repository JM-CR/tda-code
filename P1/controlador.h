// Implementation for the controller.
// Author: Gabriela Rojano
// File: controlador.h
// Date: 17/02/20

#ifndef CONTROLADOR_H
#define CONTROLADOR_H

// -----------------------------
// System headers
// -----------------------------
#include <stdbool.h>
#include "model.h"


// -----------------------------
// Public interface
// -----------------------------

/* Function prototypes */

/**
 * Appends data to an array of initial values.
 *
 * @param value the initial value
 */
void addInitialValue(double value);

/**
 * Appends data to an array of coefficients of the differential equation.
 *
 * @param coef the coefficientof each ordered
 */
void addCoefficient(double coef);

/**
 * Appends data to an array of steps. 
 *
 * @param span the lapse of time
 * @param numMuestras the width of slices
 */
bool makeSteps(double span, int numMuestras);

/**
 * Sends the order.
 *
 * @param or the order of the EDO
 */
void addOrder(int or);

#endif
