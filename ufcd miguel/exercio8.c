#include <stdio.h>

int main()
{
    int temperatura =0;

    //1.introduzir temperatura inicial
    printf("introduza temperatura");
    scanf("%d",&temperatura);

    //2.enquanto temperatura for superior a 40,continua a pedir para introduzir a temperatura
    //simulacao de temperatura,através do teclado.
    while (temperatura>40)
    {
        printf("introduza a temperatura");
        scanf("%d ,&temperatura");

    }
 return 0;    
}