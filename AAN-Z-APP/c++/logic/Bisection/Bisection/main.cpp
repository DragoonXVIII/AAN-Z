#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return pow(x, 4) + 5*pow(x, 2) - 3*x - 15;
}

void bisekcja(double a, double b, double epsilon)
{
    int counter=0;
    if(f(a)*f(b) >= 0)
    {
        cout<<"ERROR: f(a)*f(b) < 0"<<endl;
        return;
    }

    double s;//=fabs(f((a+b)/2.0));
    //for(int i =0;i<10;i++)
    while(fabs(f((a+b)/2.0)) >= epsilon)
    {
        s = (a+b)/2.0;
        if(f(a)*f(s)<0)
            b=s;
        else
            a=s;
        counter++;
    }
    s = (a+b)/2.0;
    counter++;
    cout<<"Wartosc funkcji: ["<<f(s)<<"], w punkcie: ["<<s<<"]"<<endl;
    cout<<"Licznik: "<<counter<<endl;
}

int main()
{
    double a,b,epsilon;
    cout<<"Podaj a: ";
    cin>>a;
    cout<<"Podaj b: ";
    cin>>b;
    cout<<"Podaj epsilon: ";
    cin>>epsilon;
    cout<<"Liczenie..."<<endl;
    bisekcja(a,b,epsilon);
    return 0;
}
