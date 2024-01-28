#include <iostream>
#include <cmath>

using namespace std;

double fE(double x, double y)
{
    return pow(y,2)/(x+1);
}

double fH(double x, double y)
{
    return y/pow(x,2);
}

double fmE(double x, double y)
{
    return 2*x*y;
}

double eulerMethod(double a, double b, double ya, int n)
{
    double h = (b - a) / n;
    double x = a;
    double y = ya;

    for (int i = 0; i < n; ++i)
    {
        y += h * fE(x, y);
        x += h;
    }

    return y;
}

double heunMethod(double a, double b, double ya, int n)
{
    double h = (b - a) / n;
    double x = a;
    double y = ya;

    for (int i = 0; i < n; ++i)
    {
        double k1 = fH(x, y);
        double k2 = fH(x + h, y + h * k1);
        y += 0.5 * h * (k1 + k2);
        x += h;
    }

    return y;
}

double modifiedEulerMethod(double a, double b, double ya, int n)
{
    double h = (b - a) / n;
    double x = a;
    double y = ya;

    for (int i = 0; i < n; ++i)
    {
        double k1 = fmE(x, y);
        double k2 = fmE(x + 0.5 * h, y + 0.5 * h * k1);
        y += h * k2;
        x += h;
    }

    return y;
}



int main()
{
    double aE = 0.0, aH = 1.0, amE = 0.0;       // Początek przedziału
    double bE = 1.0, bH = 1.5, bmE = 0.5;       // Koniec przedziału
    double yaE = 3.0, yaH = 2.0, yamE = 1;      // Wartość y(a)
    int nE = 5, nH = 2, nmE = 2;                // Liczba podziałów przedziału [a, b]

    cout<<"Metoda Eulera: y("<<bE<<") = "<<eulerMethod(aE, bE, yaE, nE)<<endl;

    cout<<"Metoda Heuna: y("<<bH<<") = "<<heunMethod(aH, bH, yaH, nH)<<endl;

    cout<<"Zmodyfikowana metoda Eulera: y("<<bmE<<") = "<<modifiedEulerMethod(amE, bmE, yamE, nmE)<<endl;

    return 0;
}
