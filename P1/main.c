#include <stdio.h>
#include <vista.h>
#include <controlador.h>

int main(){
    int v = askOrder();
    addOrder(v);
    for (int i = 0; i<v;i++){
        char k[3];
        itoa(v-i,k,10);
        askCoefficients(k);
    }
    for (int i = 0; i<v;i++){
        char k[3];
        itoa(v-i,k,10);
        askInitialValue(k);
    }
    double y= askSpan();
    double x = askSteps();
    bool resultado = makeSteps(y,x);
    return 0;
}