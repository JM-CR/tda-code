
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
int initial_values[];
int coefficients[];
int steps[];

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
 * @param initial_date the initial date to predict
 * @param final_date the final date to predict
 * @param time_step the large of every step begin the initial date and end with the final date
 */
void makeSteps(int initial_date, int final_date, int time_step);
/**
 * Send order 
 *
 * @param or the order of the EDO
 */
void addOrder(int or);