//REALIZA EL CALCULO DE UNA POTENCIA USANDO SUMAS DE UNA FORMA RECURSIVA
#include <stdio.h>
int x = 0;
int multiplicacion(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a + multiplicacion(a, b - 1);
}
int potencia(int b, int e) {
    if (e == 0) {
        return 1;
    }
    return multiplicacion(b, potencia(b, e - 1));
}
int main() {
    int b, e;
    printf("Base: ");
    scanf("%d", &b);
    printf("Exponente: ");
    scanf("%d", &e);    
    x = potencia(b, e);
    printf("%d ^ %d = %d\n", b, e, x);
    return 0;
}
//FIN
