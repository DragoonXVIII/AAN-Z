#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int silnia(int n)
{
    int result = 1;
    for (int i=1;i<=n;i++)
    {
        result*=i;
    }
    return result;
}

int maxT(const int table[], int size)
{
    int najwieksza = table[0];
    for(int i=1;i<size;i++)
    {
        if(table[i] > najwieksza)
        {
            najwieksza = table[i];
        }
    }
    return najwieksza;
}

int main()
{
    //wprowadzanie
    int n,m=0;
    cout<<"Wprowadz liczbe wezlow: ";
    cin>>n;

    double valuesX[n];
    cout<<"Wprowadz wartosci wezlow: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>valuesX[i];
    }

    int timesY[n]; //times cuz why not? i was lacking proper word
    cout<<"Wprowadz kolejno liczbe krotnosci wezlow: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Podaj krotnosci wezla x"<<(i+1)<<": ";
        cin>>timesY[i];
        m+=timesY[i];
    }

    double valuesY[n][maxT(timesY,n)];
    cout<<"Wprowadz kolejno wartosci krotnosci wezlow: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<timesY[i];j++)
        {
            cout<<"Podaj "<<(j+1)<<" krotnosc wezla x"<<(i+1)<<": ";
            cin>>valuesY[i][j];
        }
    }

    double searchedX;
    cout<<"Podaj punkt ktorego wartosci szukasz: ";
    cin>>searchedX;

    /*
    int n = liczba wezlow
    int m = calkowita liczba wezlow (z powtorzeniami)
    double x[n] = tabela wartosci wezlow (x)
    timesY[n] = tabela krotnosci wezlow
    valuesY[n][maxT(timesY,n) = tabela wartosci (y) i pochodnych x[n] <=> valuesY[n][...]
    */

    //sprawdzanie
    for(int c = 0; c < n; c++)
    {
        if(c != 0)
        {
            if(valuesX[c] < valuesX[c - 1])
            {
                cout << "error: ciag nieposortowany" << endl;
                return 0;
            }
        }
    }
    if(searchedX >= valuesX[0] && searchedX <= valuesX[n - 1])
    {
        cout << "Dane wprowadzone prawidlowo." << endl;
    }
    else
    {
        cout << "error: szukany x jest poza zasiegiem wezlow interpolacyjnych" << endl;
        return 0;
    }

    //liczenie
    double HermitDQ[m][m]; //Differential quotients (used in mid formula calculations)
    string HermitDQHLP[m][m+1];
    string HermitDQS[m][m]; //String Differential quotients (used in formula builder)
    double HermitFDQ[m]; //final Differential quotients
    double HermitPT[m]; //Hermit polynomal table (used in final formula calculations)
    string HermitPTS[m]; //Hermit polynomal table (used in final formula builds)
    double result;      //result value DOUBLE
    string resultS;     //result formula STRING
    //double y[m];
    double x[m];

    //zapelnienie tabeli y[m], x[m]
    int f=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<timesY[i];j++)
        {
            //y[f]=valuesY[i][0];
            x[f]=valuesX[i];
            //cout<<y[f]<<endl;
            f++;
        }
    }

    //wpisanie y do tabeli Hermita
    int counter=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<timesY[i];j++)
        {
            HermitDQ[counter][0]=valuesY[i][0];
            HermitDQHLP[counter][1]=to_string(valuesY[i][0]);
            HermitDQHLP[counter][0]=to_string(valuesX[i]);
            counter++;
        }
    }

    //zapelnienie reszty tabeli "s"
    for(int i=0;i<m;i++)
    {
        for(int j=2;j<m+1;j++)
        {
            HermitDQHLP[i][j]="s";
        }
    }

    //calculating & testing
    // i -> kolejne wiersze
    // j -> kolejne kolumny
    for(int j=2;j<m+1;j++)
    {
        int hlpvar=0;
        for(int i=1;i<m;i++)
        {
            if(HermitDQHLP[i][j-1]==HermitDQHLP[i-1][j-1] && (HermitDQHLP[i][j-1]!="s" && HermitDQHLP[i-1][j-1]!="s") && HermitDQHLP[i][0]==HermitDQHLP[i-1][0])
            {
                HermitDQHLP[i][j]="1.0";
            }
            if(HermitDQHLP[i][0]==to_string(valuesX[hlpvar]))
            {
                if(HermitDQHLP[i][j-1]==HermitDQHLP[i-1][j-1] && (HermitDQHLP[i][j-1]!="s" && HermitDQHLP[i-1][j-1]!="s")) //sgs
                    HermitDQHLP[i][j]=to_string(valuesY[hlpvar][j-1]);
            }
            else
            {
                hlpvar++;
            }
            //napisz wpisanie 1 i czegos innego zeby wiadomo bylo co zrobic np stopien silni on chyba jes skorelowany z pochodna jako index?
        }
        //X NIE DZIALAJA BO NIE MA TABLICY x[m] TYLKO x[n] czyli w przykladzie x[2] a nie x[5]xd - FIXED
    }

    /*for(int i=0;i<m;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(HermitDQHLP[i][j]!="s")
                cout<<stoi(HermitDQHLP[i][j])<<"; ";
            else
                cout<<"s; ";
        }
        cout<<endl;
    }*/

    //testing

    cout<<"TEST HERMITDQHLP[][];"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            cout<<HermitDQHLP[i][j]<<"; ";
        }
        cout<<endl;
    }
    cout<<"END TEST"<<endl;


    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            HermitDQ[i][j]=0.0;
        }
    }

    for(int i=0;i<m;i++)
    {
        int hlpvar=i;
        for(int j=0;j<m;j++)
        {
            if(HermitDQHLP[i][j+1]!="s")
            {
                HermitDQ[i][j]=stod(HermitDQHLP[i][j+1])/(double)silnia(j);
                HermitDQS[i][j]=HermitDQHLP[i][j+1]+"/"+to_string(j)+"!";
                if(i==j)
                    HermitFDQ[i]=HermitDQ[i][j];
                if(i==0)
                {
                    HermitPT[i]=1;
                    HermitPTS[i]="";
                }
            }
            else
            {
                if(j<=i)
                {
                    HermitDQ[i][j]=(HermitDQ[i][j-1]-HermitDQ[i-1][j-1])/(x[i]-x[hlpvar]);
                    HermitDQS[i][j]="("+to_string(HermitDQ[i][j-1])+" - "+to_string(HermitDQ[i-1][j-1])+")/("+to_string(x[i])+" - "+to_string(x[hlpvar])+")";
                    if(i==j)
                        HermitFDQ[i]=HermitDQ[i][j];
                }
            }
            hlpvar--;
        }
        if(i==0)
        {
            HermitPT[i]=1;
            HermitPTS[i]="";
        }
        else
        {
            HermitPT[i]=HermitPT[i-1]*(searchedX-x[i-1]);
            HermitPTS[i]=HermitPTS[i-1]+"("+to_string(searchedX)+" - "+to_string(x[i-1])+")";
        }
    }

    //cout results
    cout<<"RESULTS DOUBLE HermitDQ"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<HermitDQ[i][j]<<"; ";
        }
        cout<<endl;
    }
    cout<<"END RESULTS DOUBLE"<<endl;

    cout<<"RESULTS STRING HermitDQS"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<HermitDQS[i][j]<<"; ";
        }
        cout<<endl;
    }
    cout<<"END RESULTS STRING"<<endl;

    result =0.0;
    resultS = "";
    for(int i=0;i<m;i++)
    {
        result+=HermitFDQ[i]*HermitPT[i];
        if(i==0)
            resultS+="("+HermitDQS[i][i]+")";
        else
            resultS+=" + ("+HermitDQS[i][i]+") * ("+HermitPTS[i]+")";
    }
    cout<<"Wynik DOUBLE to: "<<result<<endl;
    cout<<"Wynik STRING to: "<<resultS<<endl;

    return 0;
}
