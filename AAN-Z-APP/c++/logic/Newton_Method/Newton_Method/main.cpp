#include <iostream>
#include <cmath>


using namespace std;


double f(double x)
{
    return exp(x)-5*x-3;
}


double df(double x)
{
    return exp(x)-5;
}


void newton(double x0, double epsilon)
{
    double x = x0;
    int iterations = 0;

    while (fabs(f(x)) >= epsilon)
    {
        x = x - f(x) / df(x);
        iterations++;
    }
    cout << "Rozwiazanie znalezione po " << iterations << " iteracjach: x = " << x << ", f(x) = " << f(x) << endl;
}

int main()
{
    double x0, epsilon;
    cout<<"Podaj x0: ";
    cin>>x0;
    cout<<"Podaj epsilon: ";
    cin>>epsilon;
    cout << "Obliczanie..." << endl;
    newton(x0, epsilon);
    return 0;
}
