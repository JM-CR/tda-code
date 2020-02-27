// Utilities to implement the Euler approximation.
// The term Ordinary Differential Equation will be abbreviated as EDO.
//
// Author: Josue Mosiah Contreras Rocha
// File: model.h
// Date: 17/02/20

#ifndef MODEL_H
#define MODEL_H

// -----------------------------
// System headers
// -----------------------------
#include <stdbool.h>
#include "gnuplot.h"


// -----------------------------
// Public interface
// -----------------------------

/* Function prototypes */

/**
 * Sets the number of desired results for the Euler's method.
 * This function must be called before processData().
 *
 * @param size Number of results to process.
 */
void setSampleSize( unsigned int size );

/**
 * Solves an EDO using the Euler's method and results are saved in the 
 * file 'solucion.dat' in GNUPlot format.
 *
 * The number of results depend on the previous call of setSampleSize().
 *
 * @param coefficients EDO's coefficients starting with the highest derivative.
 * @param initialValues Initial conditions starting with the highest order.
 * @param order Exponent of the greatest derivative.
 * @param steps Times to traverse.
 * @return True if all operations were correct.
 */
bool processData( double *coefficients, double *initialValues, size_t order, double *steps );

#endif