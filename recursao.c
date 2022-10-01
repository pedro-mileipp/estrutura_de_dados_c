#include <stdio.h>
#include <stdlib.h>

int potencia(int base, int exp){
    // toda função recursiva tem um caso de parada  
    if(exp == 1){
        return base;
    }
    return base*potencia(base, exp-1);
}

int main(int argc, char const *argv[])
{
    int v = potencia(2, 4); //16
    printf("%d", v);
    return 0;
}
