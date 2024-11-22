#include <stdio.h>
//FUNCION RECURSIVA PARA CALCULAR EL TERMINO n DE LA SUCECION DE FIBONACCI
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1; 
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int n;
    printf("Ingrese la cantidad de numeros de Fibonacci a mostrar: ");
    scanf("%d", &n);
    printf("\nLos primeros %d numeros de la sucesion de Fibonacci son:\n", n);
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d.", fibonacci(i));
        } else {
            printf("%d, ", fibonacci(i));
        }
    }
    printf("\n");
    return 0;
}
//FIN
