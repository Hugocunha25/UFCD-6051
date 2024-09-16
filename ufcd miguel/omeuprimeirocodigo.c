#include <stdio.h>

int main()
{
    char character;
    printf("introduza o caracter:\t");
    scanf("%c",&character);
   
    printf("ola mundo\n");
    printf("      %c   \n",character);
    printf("     %c%c%c  \n",character,character,character);
    printf("    %c%c%c%c%c \n",character,character,character,character,character);
    printf("   %c%c%c%c%c%c%c \n",character,character,character,character,character,character,character);
    
    return 0;
    
}