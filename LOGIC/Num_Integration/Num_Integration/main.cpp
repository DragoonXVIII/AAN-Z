#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int choice;
    cout<<"Wybierz wzor funkcji:"<<endl;
    cout<<"1. sin^2 x + 2  <-2Pi;0>"<<endl;
    cout<<"2. e^x * 2x^3  <0;2>"<<endl;
    cin>>choice;
    int formula;
    cout<<"Wybierz metode: "<<endl;
    cout<<"1. wzor trapezow "<<endl;
    cout<<"2. wzor Simpsona "<<endl;
    cin>>formula;
    int accuracy;
    cout<<"Podaj dokladnosc(ilosc przedzialow): ";
    cin>>accuracy;

    if(formula==2 && accuracy%2==1)
    {
        cout<<"blad dokaldnosci! nieparzysta!";
        return 0;
    }

    if(choice==1) //funkcja sinus powinno byc 15.708
    {
        if(formula==1) //Funkcja: sin^2 x + 2 w zakresie (2PI;0) metodą Trapezówe)
        {
            double height = 6.2831853/accuracy;
            double result = 0.0;

            for(int i=0;i<accuracy;i++)
            {
                double x0 = i*height;
                double x1 = (i+1)*height;
                double area = ((pow(sin(x0),2)+2) + (pow(sin(x1),2)+2)) * height / 2;
                result+=area;
            }
            cout<<result;
        }
        else if(formula==2)  //Funkcja: sin^2 x + 2 w zakresie (2PI;0) metodą Simpsona
        {
            double width = 6.2831853 / accuracy;
            double results[accuracy+1];

            for(int i=0;i<=accuracy;i++)
            {
                double x = i * width;
                double f_x = pow(sin(x),2)+2;
                results[i] = f_x;
            }

            double result = 0.0;
            double simpson4 = 0.0;
            double simpson2 = 0.0;

            for(int i=0;i<=accuracy;i++)
            {
                if(i==0 || i==accuracy)
                    result+=results[i];
                else if(i%2 == 1)
                    simpson4 += results[i];
                else if(i % 2 == 0)
                    simpson2 += results[i];
            }
            result = width / 3 * (result + 4 * simpson4 + 2 * simpson2);
            cout << result;
        }
        else
        {
            cout<<"error";
        }
    }
    else if(choice==2) // funkcja e powinno byc 41.556
    {
        if(formula==1) // Funkcja: e^x * 2x^3 w zakresie (0;2) metodą Trapezów
        {
            double height = 2.0/accuracy;
            double result = 0.0;

            for(int i=0;i<accuracy;i++)
            {
                double x0 = i*height;
                double x1 = (i+1)*height;
                double area = ( (exp(x0) * 2 * pow(x0, 3)) + (exp(x1) * 2 * pow(x1, 3)) ) * height / 2;
                result+=area;
            }
            cout<<result;
        }
        else if(formula == 2) // Funkcja: e^x * 2x^3 w zakresie (0;2) metodą Simpsona
        {
            double width = 2.0 / accuracy;
            double results[accuracy+1];

            for(int i=0;i<=accuracy;i++)
            {
                double x = i * width;
                double f_x = exp(x) * 2 * pow(x, 3);
                results[i] = f_x;
            }

            double result = 0.0;
            double simpson4 = 0.0;
            double simpson2 = 0.0;

            for(int i=0;i<=accuracy;i++)
            {
                if(i==0 || i==accuracy)
                    result+=results[i];
                else if(i%2 == 1)
                    simpson4 += results[i];
                else if(i % 2 == 0)
                    simpson2 += results[i];
            }
            result = width / 3 * (result + 4 * simpson4 + 2 * simpson2);
            cout << result;
        }
        else
        {
            cout << "error";
        }
    }
}

