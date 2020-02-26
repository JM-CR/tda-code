
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
 * Ask data of initial values
 * @param text which initial value we want
 */
double askInitialValue(char *text);

/**
 * Ask coefficients of the differential equation
 * @param text which cofficient we want
 */
double askCoefficients(char *text);

/**
 * Ask span of time  
 *
 */
double askSpan();

/**
 * Ask steps to divide the span of time
 *
 */
double askSteps();

/**
 * Ask order of the equation 
 *
 */
int askOrder();