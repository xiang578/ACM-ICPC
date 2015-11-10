#include<stdio.h>

int main()
{
    double n;
    double x, y;
    while (scanf("%lf", &n) != EOF)

    {
        if (n == 0) break;
        scanf("%lf%lf", &x, &y);
        int k = 1;
        if (x - y == 0&&x<=n) printf("NO\n");
        else
        {
            while (1)
            {
                n = n - x;
                if (n <= 0.00001)
                {
                    printf("%d\n", k);
                    break;
                }
                else
                {
                    n = n + y;
                    k++;
                }
            }
        }
    }
    return 0;
}
