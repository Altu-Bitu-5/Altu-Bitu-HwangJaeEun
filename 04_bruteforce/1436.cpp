#include <stdio.h>
 
int main(void)
{
    int i, n, tmp, cnt=0, check;
    scanf("%d", &n);
    
    for (i=666; ; i++)
    {
        tmp = i;
        check = 0;
        while(tmp)
        {
            if (tmp % 1000 == 666)
                check ++;
            tmp /= 10;
        }
        if (check)
        {
            cnt ++; 
            if (cnt == n)
                break;
        }
    }
    printf("%d", i);
    return 0;
}