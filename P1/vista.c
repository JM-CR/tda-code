// See vista.h for more information.
// Author: Rodrigo Roberto Arce
// File: vista.c
// Date: 27/02/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include "vista.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private functions */

/**
 * Checks if there is an error from the user's input.
 * 
 * @param succesful Number of succesful assignments.
 * @return True if there was an error; otherwise, false.
 */
static inline bool inputError( int succesful ) {
	return succesful <= 0;
}

/**
 * Tries to read a value until the user has the correct input.
 *
 * @return The user's value.
 */
static double readValue( void ) {
    double value;
    int userValue = scanf("%lf", &value);
    while ( inputError(userValue) ) {
        scanf("%*s");
        printf("Ingresa un número válido: ");
        userValue = scanf(" %lf", &value);
    }
    return value;
}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

void initialRun(void) {
    printf(
        "\nEste programa grafica la solución de una EDO usando GNUPlot."
        "\n\nLa ecuación será introducida de la siguiente forma:"
        "\n\t1. Orden (n)."
        "\n\t2. Coeficientes de la ecuación (c)."
        "\n\t3. Valores iniciales (y)."
        "\n\t4. Número de muestras y tiempo final a graficar."
        "\n\n\ty_n + c_n*y_(n-1) + c_(n-1)*y_(n-2) + ... + c_1*y_1 = f(t) "        
        "\n\n"
    );
}

double askInitialValue( char *text ){
    printf("Ingresa valor inicial y_%s: ",text);
    return readValue();
}

double askCoefficients( char *text ) {
    printf("Ingresa el coeficiente c_%s: ",text);
    return readValue();
}

double askSpan(void) { 
    printf("Tiempo final a calcular (tf): ");
    return readValue();
}

int askSampleSize(void) {
    printf("Número de muestras entre [0, tf): ");
    return readValue();
}

int askOrder(void) {
    printf("Ingresa el orden de la EDO: ");
    return readValue();  
}
