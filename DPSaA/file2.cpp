#include <stdio.h>

int main()
{
    for(int a=0; a< 100; a++)
        for(int b=0; b< 100; b++)
            for(int c=0; c< 100; c++)
            {   
                if((a-b)-c == a - (b-c))
                {
                    printf("(%d %d %d)\n", a,b,c);
                }
            }

    return 0;
}