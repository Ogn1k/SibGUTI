#include <stdio.h>

int factorial(double n)
{
    int fact=1;
    for (int i = 1; i <= n; i++){
        fact *= i;  
    }
    return fact;
}

int pasha(int year)
{
    int a, b, c, d, e, f;
    a = year % 19;
    b = year % 4;
    c = year % 7;
    d = (19*a + 15)%30;
    e = (2*b + 4*c + 6*d + 6) % 7;
    f = d+e;
    if(f <= 26)
        printf("%d.04", f +4);
    else
        printf("%d.05", f-26);
    return 0;
}

double grade(double x, int n)
{
    double t = 1;
    if(n<0)
    {
        x=1/x;
        n= -n;
    }
    for(int i=0;i<n;++i)
        t *= x;
    return t;
}

double abs(double n)
{
    if(n<0)
        return n*-1;
    return n;
}

double cosTaylor(double x) {
    double result = 0.0;
    double term = 1.0;
    int n = 0;
    while (abs(term) > 0.0001) {
        term = grade(-1, n) * grade(x, 2 * n) / factorial(2 * n);
        result += term;
        n++;
    } 
    return result;
}

int main()
{
    int year= 2000;
    pasha(year);

    int y, n;
    printf("\n%d", grade(2, 3));

    double x;
    printf("\n%f", cosTaylor(2));
    return 0;
}

