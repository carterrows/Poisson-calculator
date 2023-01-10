//Poisson calculator
//Made by Carter Rows

#include <stdio.h>
#include <math.h>

double poisson(double a, double b);
double factorial(double n);

int main()
{
    printf("\nWelcome to my Poisson distribtuion calculator!\n");

    double lambda;
    printf("\nPlease enter your value for lambda:\t");
    scanf("%lf", &lambda);

    double x;
    printf("Please enter your 'x' value:\t");
    scanf("%lf", &x);

    //probability X = x
    double equal = poisson(lambda, x);
    printf("\nP(X = %.0lf) = %.5lf \n", x, equal);

    //probability X <= x
    double lessEqual = 0;
    for(int i = 0; i <= x; i++)
    {
        lessEqual += poisson(lambda, i);
    }
    printf("\nP(X <= %.0lf) = %.5lf\n", x, lessEqual);

    //probability X < x
    double less;
    less = lessEqual - equal;
    printf("P(X < %.0lf) = %lf\n", x, less);

    //probability X >= x
    double greaterEqual = 0;
    for(int j = 0; j < x; j++)
    {
        greaterEqual += poisson(lambda, j);
    }
    printf("\nP(X >= %.0lf) = %.5lf\n", x, (1 - greaterEqual));

    //probability X > x
    double greater;
    greater = 1 - greaterEqual - equal;
    printf("P(X > %.0lf) = %.5lf\n\n", x, greater);
    
    return 0;
}

double factorial(double n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

double poisson(double a, double b)
{
    double temp1 = pow(a, b) / exp(a);
    double fact = factorial(b);
    
    return (temp1 / fact);
}
