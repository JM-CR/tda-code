// See vista.h for more information.
// Author: Gabriela Rojano
// File: vista.c
// Date: 27/02/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include "vista.h"


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

double askInitialValue( char *text ){
    double value;
    printf("Ingresa valor inicial y_%s: ",text);
    scanf("%lf", &value);
    return value;
}

double askCoefficients( char *text ) {
    double value;
    printf("Ingresa el coeficiente c_%s: ",text);
    scanf("%lf", &value);
    return value;
}

double askSpan(void){ 
    double span;
    printf("Tiempo final a calcular (tf): ");
    scanf("%lf", &span);
    return span;
}

int askSampleSize(void) {
    int samples;
    printf("Número de muestras entre [0, tf): ");
    scanf("%d", &samples);
    return samples;
}

int askOrder(void){
    int order;
    printf("Ingresa el orden de la EDO: ");
    scanf("%d", &order);
    return order;  
}
