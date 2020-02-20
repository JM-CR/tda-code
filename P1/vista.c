// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include "controlador.h"
#include "vista.h"


// -----------------------------
// Public elements
// -----------------------------

int order;
int span;
int steps;
/* Implementation of the public functions */

double askInitialValue( char *text ){
    double value;
    printf("Ingresa valor inicial %s: \n",text);
    scanf("%lf", &value);
    return value;
}

double askCoefficient( char *text ){
    double value;
    printf("Ingresa valor inicial %s: \n",text);
    scanf("%lf", &value);
    return value;
}

double askSpanSteps(){ //puedo regresar tuplas?
    double span;
    double steps;
    printf("Ingresa el numero del lapso:\n");
    scanf("%lf", &span);
    getchar();
    printf("Ingresa el numero en el qeu se dividira el lapso :\n");
    scanf("%lf", &steps);
    getchar();
    makeSteps(span, steps);
}

void askOrder(){
    printf("Ingresa el orden de la EDO:\n");
    scanf("%d", &order);
    addOrder(order);
    getchar();
}

