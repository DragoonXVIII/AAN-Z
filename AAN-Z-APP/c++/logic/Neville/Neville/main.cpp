#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Podaj liczbe wezlow: ";
    cin >> n;

    double x[n];
    double y[n];
    double NevilleT[n][n];
    string NevilleTS[n][n];
    double searchedX;
    double result;

    cout<<"Wprowadz wartosci wezlow: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    cout<<"Wprowadz wartosci funkcji w kolejnych wezlach: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>y[i];
    }
    cout << "Podaj punkt, ktorego wartosci funkcji szukasz: " << endl;
    cin >> searchedX;

    //checking data validation
    for(int c = 0; c < n; c++)
    {
        if(c!=0)
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

    for(int j=0;j<=n;j++)
    {
        for(int i=0;i<n-j;i++)
        {
            if(j==0)
            {
                NevilleT[i][0]=y[i];
                NevilleTS[i][0]=to_string(y[i]);
            }
            else
            {
                NevilleT[i][j]=(((searchedX-x[i])*NevilleT[i+1][j-1]) - ((searchedX-x[i+j])*NevilleT[i][j-1])) / (x[i+j]-x[i]);
                NevilleTS[i][j]="((("+to_string(searchedX)+"-"+to_string(x[i])+")*("+to_string(NevilleT[i+1][j-1])+")) - ((";
                NevilleTS[i][j]+=to_string(searchedX)+"-"+to_string(x[i+j])+")*("+to_string(NevilleT[i][j-1])+"))) / ("+to_string(x[i+j])+"-"+to_string(x[i])+")";
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<NevilleT[i][j]<<"; ";
        }
        cout<<endl;
    }

    cout<<endl<<endl<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<NevilleTS[i][j]<<"; ";
        }
        cout<<endl;
    }

    result = NevilleT[0][n-1];
    cout << "Przyblizona wartosc funkcji w punkcie p: " << result << endl;

    return 0;
}
