// View for the program.
// Author: Gabriela Rojano
// File: vista.h
// Date: 27/02/20

#ifndef VISTA_H
#define VISTA_H

// -----------------------------
// Public interface
// -----------------------------

/* Function prototypes */

/**
 * Ask initial values.
 *
 * @param text which initial value we want
 */
double askInitialValue(char *text);

/**
 * Ask coefficients for the differential equation.
 *
 * @param text which cofficient we want
 */
double askCoefficients(char *text);

/**
 * Asks span of time.
 */
double askSpan(void);

/**
 * Asks steps to divide the span of time.
 */
int askSampleSize(void);

/**
 * Asks order of the equation.
 */
int askOrder(void);

#endif