#include <stdio.h>

int main()
{

    int x = 0;
    int y = 0;

    x = 10;
    y = 5;

    int sum = x + y;

    printf("sum: %d", sum);
    
    scanf("%d",&x);
    scanf("%d",&y);
    
    printf("sum: %d", x+y);

     return 0;

}
