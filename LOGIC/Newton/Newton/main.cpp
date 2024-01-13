#include <iostream>

using namespace std;

int main()
{

    int n;
    cout<<"Wprowadz liczbe wezlow: ";
    cin>>n;

    double x[n];
    double y[n];
    double NewtonDQ[n][n]; //Differential quotients
    string NewtonDQS[n][n]; //String Differential quotients (for formula builder)
    double NewtonFDQ[n]; //final Differential quotients
    double NewtonPT[n]; //Newton polynomal table (used in final formula calculations)
    string NewtonPTS[n]; //Newton polynomal table (used in final formula builds)
    double searchedX;   //searched point
    double result;      //result value DOUBLE
    string resultS;     //result formula STRING

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

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            NewtonDQ[i][j]=0.0;
        }
    }

    for(int i=0;i<n;i++)
    {
        int hlpvar=i;
        for(int j=0;j<n;j++)
        {
            if(j==0)
            {
                NewtonDQ[i][j]=y[i];
                NewtonDQS[i][j]=to_string(y[i]);
                NewtonFDQ[i]=NewtonDQ[i][j];
            }
            else if(j<=i)
            {
                NewtonDQ[i][j]=(NewtonDQ[i][j-1]-NewtonDQ[i-1][j-1])/(x[i]-x[hlpvar]);
                NewtonDQS[i][j]="("+to_string(NewtonDQ[i][j-1])+" - "+to_string(NewtonDQ[i-1][j-1])+")/("+to_string(x[i])+" - "+to_string(x[hlpvar])+")";
                if(i==j)
                    NewtonFDQ[i]=NewtonDQ[i][j];
                //cout<<"indexy x["<<i<<"] oraz x["<<hlpvar<<"]"<<endl;
            }
            hlpvar--;
        }
        if(i==0)
        {
            NewtonPT[i]=1;
            NewtonPTS[i]="";
        }
        else
        {
            NewtonPT[i]=NewtonPT[i-1]*(searchedX-x[i-1]);
            NewtonPTS[i]=NewtonPTS[i-1]+"("+to_string(searchedX)+" - "+to_string(x[i-1])+")";
        }
    }

    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                cout<<NewtonDQ[i][j]<<endl;
        }
    }*/

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<NewtonDQ[i][j]<<" ; ";
        }
        cout<<endl;
    }

    //cout<<endl<<endl<<endl;

    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<NewtonDQS[i][j]<<" ; ";
        }
        cout<<endl;
    }*/

    //double NewtonFDQ[n]; // final -||-
    //double NewtonPT[n];

    result =0.0;
    resultS = "";
    for(int i=0;i<n;i++)
    {
        result+=NewtonFDQ[i]*NewtonPT[i];
        if(i==0)
            resultS+="("+NewtonDQS[i][i]+")";
        else
            resultS+=" + ("+NewtonDQS[i][i]+") * ("+NewtonPTS[i]+")";
    }
    cout<<"Wynik to: "<<result<<endl<<resultS;

    return 0;
}
