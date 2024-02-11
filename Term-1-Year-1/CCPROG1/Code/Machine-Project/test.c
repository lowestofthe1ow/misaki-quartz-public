#include <stdio.h>
#include <math.h>

double approxSqrt (double x, double y, double old)
{
        printf("x: %lf, y: %lf, old: %lf\n", x, y, old);
        if (fabs(old - y) >= fabs(y * 0.00001))
                return approxSqrt (x, (y + x / y) / 2, y);
        else
                return y;
}

int main ()
{
        /*double num;
        
        printf("Enter a number: ");
        scanf("%lf", &num);
        
        printf("%lf", approxSqrt(num, 1, num));
        
        return 0;*/
        printf("%10.2e", 1277.);
}
