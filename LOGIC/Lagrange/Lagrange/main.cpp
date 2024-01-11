#include <iostream>



using namespace std;



int main()
{
    int n;
    cout << "Podaj liczbe wezlow: ";
    cin >> n;

    double x[n];
    double y[n];
    double searchedX;
    double LagrangeFP[n]; //Lagrange Fundamental Polynomal
    string LagrangeFPS[n][n]; //
    bool uniqueNodes = true;

    cout << "Podaj wartosci wezlow:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    cout << "Podaj wartosci funkcji w tych wezlow:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }

    //Sprawdzenie warunku interpolacji (unikalność węzłów)
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (x[i] == x[j])
            {
                uniqueNodes = false;
                break;
            }
        }
    }

    if (!uniqueNodes)
    {
        cout << "Warunek interpolacji nie jest spelniony - wezly nie sa unikalne." << endl;
    }
    else
    {
        // Podaj punkt, dla którego chcesz obliczyć wartość interpolowaną
        cout << "Podaj punkt, dla ktorego chcesz obliczyc wartosc interpolowana: ";
        cin >> searchedX;

        for(int j=0;j<n;j++)
        {
            double result = 1.0;
            for(int i=0;i<n;i++)
            {
                if(i!=j)
                {
                    result*=(searchedX-x[i])/(x[j]-x[i]);
                    LagrangeFPS[j][i]="(x-"+to_string(x[i])+")/("+to_string(x[j])+"-"+to_string(x[i])+")";
                }
            }
            LagrangeFP[j]=result;

        }


        double result = 0.0;
        for(int i=0;i<n;i++)
        {
            result+=(LagrangeFP[i]*y[i]);
        }
        cout << "Wynik interpolacji w punkcie " << searchedX << " to " << result << endl;
    }

    cout<<endl;

    for(int j=0;j<n;j++)
    {
        cout<<to_string(y[j])<<" * {";
        for(int i=0;i<n;i++)
        {

            cout<<LagrangeFPS[j][i];
        }
        cout<<"}"<<endl;
    }
    return 0;
}


/*
 *
 * class LagrangeInterpolation
{

public:

    int n;
    double x[n];
    double y[n];
    double searchedX;
    double LagrangeFP[n];
    string LagrangeFPS[n-1][n];
    bool uniqueNodes = true;

    LagrangeInterpolation(int n){this->n = n;};
    ~LagrangeInterpolation(){};



};
 */
