// See model.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: model.c
// Date: 17/02/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include "model.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private global variables */

static size_t sampleSize;   // Number of results

/* Private functions */

/**
 * Calculates the approximation 'Yn'.
 *
 * @param coefficients EDO's coefficients starting with the highest derivative.
 * @param initialValues Initial conditions at given time.
 * @param order Exponent of the greatest derivative.
 * @param step Time to calculate.
 * @return Approximate point Yn.
 */
static double getPoint( double *coefficients, double* initialValues, size_t order, double step ) {
	// Cumulative calculations
	double sum = initialValues[order - 1];
	for ( unsigned int i = 0; i < order; ++i )
		sum -= coefficients[i] * initialValues[i];

	// Result
	return initialValues[0] + step * sum;
}

/**
 * Calculates the next iteration of a derivative.
 * Used when the order is higher than one.
 *
 * @param values Current conditions (e.g. [Y(t_n), Y'(t_n)]).
 * @param step Initial time.
 * @return Value of the next iteration.
 */
static double nextValue( double* values, double step ) {
	return values[0] + step * values[1];
}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

void setSampleSize( unsigned int size ) {
	sampleSize = size;
}

double *processData( double *steps, double *coefficients, double *initialValues, size_t order ) {
	
}
