#include <stdio.h>

int main()
{
    int n, a = 0, b = 1, c, i;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n == 0)
        printf("The 0th Fibonacci term is 0");
    else if (n == 1)
        printf("The 1st Fibonacci term is 1");
    else
    {
        for (i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        printf("The %dth Fibonacci term is %d", n, b);
    }

    return 0;
}