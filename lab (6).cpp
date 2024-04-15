#include <iostream>
#include <math.h>

int factorial(double n)
{
    int fact=1;
    for (int i = 1; i <= n; i++){
        fact *= i;  
    }
    return fact;
}

int SP(double a, double *b, double &c)
{
    if(a<*b+c && *b<a+c && c<*b+a)
    {
        double p=(a+*b+c)/2;
        double P=(a+*b+c);
        double s=pow((p*(p-a)*(p- *b)*(p-c)), 0.5);
        std::cout << s << " " << P << std::endl;
        *b = s; c = P;
        return 1;
    }
    return 0;
}

void probability(int n, int m, double p, double &pg, double &pb)
{
    if(n<0 || m<0 || m>n)
    {
        std::cout << "wrong" << std::endl;
        return;
    }
    double c = factorial(n)/(factorial(m)*factorial(n-m));
    pg=c*pow(p,m)*pow(1-p,n-m);
    pb=c*pow(1-p,m)*pow(p,n-m);
}

int main()
{
    //1
    {
        double a=1, b=1, c=1;
        SP(a, &b, c);
        std::cout << b << " " << c << std::endl;
    }
    //2
    {
        int n=10, m=6;
        double p=0.45, pg, pb;
        probability(n,m,p,pg,pb);
        std::cout << "\n" << pg << std::endl;
        std::cout << pb << std::endl;
    }
}