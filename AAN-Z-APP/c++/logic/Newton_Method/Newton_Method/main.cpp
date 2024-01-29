#include <iostream>
#include <cmath>


using namespace std;


double fz(double x)
{
    return exp(x)-5*x-3;
}

double dfz(double x)
{
    return exp(x)-5;
}


double f(double x)
{
    return sin(x)-(x/2.0);
}

double df(double x)
{
    return cos(x)-(1.0/2.0);
}

void newton(double x0, double epsilon)
{
    double x = x0;
    int iterations = 0;

    while(fabs(f(x)) >= epsilon)
    {
        x = x - (f(x) / df(x));
        iterations++;
        cout << "iteracja: " << iterations << "; x = " << x << ", f(x) = " << f(x) << endl;
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
