// See model.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: model.c
// Date: 17/02/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "model.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private global variables */

static size_t sampleSize;   // Number of results

/* Private functions */

/**
 * Implementation for the 'f(t)' function.
 * 
 * @param t Time to evaluate.
 * @return Point at given time.
 */
static double evaluate( double t ) {
	return sin(4*3.1416*t);
}

/**
 * Calculates the approximation 'Yn'.
 *
 * @param coefficients EDO's coefficients starting with the highest derivative.
 * @param initialValues Initial conditions at given time.
 * @param order Exponent of the greatest derivative.
 * @param step d_t.
 * @param time Time to calculate.
 * @return Approximate point Yn.
 */
static double getPoint( double *coefficients, double* initialValues, size_t order, double step, double time ) {
	// Cumulative calculations
	double sum = evaluate(time);
	for ( unsigned int i = 0; i < order; ++i )
		sum += coefficients[i] * initialValues[i];

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

bool processData( double *coefficients, double *initialValues, size_t order, double *steps ) {
	// Evalute arguments
	if ( coefficients == NULL || initialValues == NULL || steps == NULL )
		return false;

	// Euler
	double results[order + 1];
	for ( unsigned int i = 0; i < sampleSize; ++i ) {
		// Save time
		results[0] = steps[i]; 

		// Save results
		for ( int j = order - 1, current = 1; j >= 0; --j )
			results[current++] = initialValues[j];
		
		// Values for the next loop
		double tempValue = getPoint(coefficients, initialValues, order, steps[1], steps[i]);
		for ( unsigned int j = order - 1; j > 0; --j ) {
			double values[2] = { initialValues[j], initialValues[j - 1] };
			initialValues[j] = nextValue(values, steps[i]);
		}
		initialValues[0] = tempValue;
	}

	return true;
}
