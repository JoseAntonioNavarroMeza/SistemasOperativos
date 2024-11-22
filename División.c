//REALIZA DIVISIONES USANDO SOLO RESTAS CON UN METODO RECURSIVO
#include <stdio.h>
int x=0,a,b;
int div(int a, int b){
    if (a>=b)
    {
        a=a-b;
        x=x+1;
        div(a,b);
        return x;
    }else{
    }
}
int main(){
    printf("Dividendo: ");
    scanf("%d", &a);
    printf("Divisor: ");
    scanf("%d", &b);
    div(a,b);
    printf("%d / %d \n",a,b);
    printf("resultado %d",x);
}
//FIN
