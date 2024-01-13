#include <iostream>

using namespace std;

int main()
{

    int n;
    cout<<"Wprowadz liczbe wezlow: ";
    cin>>n;

    double x[n];
    double y[n];
    double NewtonDQ[n]; //Differential quotients
    double searchedX;

    cout<<"Wprowadz wartosci wezlow: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[n];
    }

    cout<<"Wprowadz wartosci funkcji w kolejnych wezlach: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>y[n];
    }

    cout << "Podaj punkt, ktorego wartosci funkcji szukasz: " << endl;
    cin >> searchedX;


    //sprawdzanie
    for(int c = 0; c < n; c++)
    {
        if(c != 0)
        {
            if(x[c] <= x[c - 1])
            {
                if (x[c] < x[c - 1])
                    cout << "error: ciag nieposortowany" << endl;
                else
                    cout << "error: ciag posiada powtorzenia" << endl;
                return 0;
            }
        }
    }
    if(searchedX >= x[0] && searchedX <= x[n - 1])
    {
        cout << "Dane wprowadzone prawidlowo." << endl;
    }
    else
    {
        cout << "error: szukany x jest poza zasiegiem wezlow interpolacyjnych" << endl;
        return 0;
    }




    return 0;
}
