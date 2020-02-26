// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include "controlador.h"
#include "vista.h"


// -----------------------------
// Public elements
// -----------------------------

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

double askSpan(){ 
    double span;
    printf("Ingresa el numero del lapso:\n");
    scanf("%lf", &span);
    return span;
}

double askSteps(){
    double steps;
    printf("Ingresa el numero en el qeu se dividira el lapso :\n");
    scanf("%lf", &steps);
    return steps;
}

int askOrder(){
    int order;
    printf("Ingresa el orden de la EDO:\n");
    scanf("%d", &order);
    return order;
    
}

