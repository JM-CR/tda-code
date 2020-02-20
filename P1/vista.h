
// -----------------------------
// System headers
// -----------------------------


// -----------------------------
// Public interface
// -----------------------------

/* Constants */

/* Types declarations */

/* Global variables */
int order;
int span;
int steps;

/* Function prototypes */

/**
 * Ask data of initial values
 *
 */
void askInitialValue();

/**
 * Ask coefficients of the differential equation
 *
 */
void askCoefficients();

/**
 * Ask span of time  
 *
 */
void askSpan();

/**
 * Ask steps to divide the span of time
 *
 */
void askSteps();

/**
 * Ask order of the equation 
 *
 */
void askOrder();