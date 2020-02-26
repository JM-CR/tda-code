
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
 * Appends data to an array of initial values
 *
 * @param value the initial value
 */
void addInitialValue(int value);

/**
 * Appends data to an array of coefficients of the differential equation
 *
 * @param coef the coefficientof each ordered
 */
void addCoefficient(int coef);

/**
 * Appends data to an array of steps 
 *
 * @param lapso the lapse of time
 * @param numMuestras the width of the slices of the lapse
 */
bool makeSteps(double lapso, double numMuestras);
/**
 * Send order 
 *
 * @param or the order of the EDO
 */
void addOrder(int or);