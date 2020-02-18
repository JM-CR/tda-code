// Utilities to implement the Euler approximation.
// The term Ordinary Differential Equation will be abbreviated as EDO.
//
// Author: Josue Mosiah Contreras Rocha
// File: model.h
// Date: 17/02/20

// -----------------------------
// System headers
// -----------------------------


// -----------------------------
// Public interface
// -----------------------------

/* Constants */

/* Types declarations */

/* Global variables */

/* Function prototypes */

/**
 * Sets the number of desired results for the Euler's method.
 * This function must be called before processData().
 *
 * @param size Number of results to process.
 */
void setSampleSize( unsigned int size );

/**
 * Solves an EDO using the Euler's method.
 * The number of results depend on the previous call of setSampleSize().
 *
 * @param steps Times to traverse.
 * @param coefficients EDO's coefficients starting with the highest derivative.
 * @param initialValues Initial conditions for the EDO.
 * @param order Exponent of the greatest derivative.
 * @return Results at each step.
 */
double *processData( double *steps, double *coefficients, double *initialValues, size_t order );
