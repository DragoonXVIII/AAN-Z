#include <iostream>


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

int main()
{
    int searchedX, degree;
    cout<<"Podaj stopien wielomianu: ";
    cin>>degree;

    int coefficients[degree+1];
    int derivatives[degree][degree]; // 0 = answer, 1 d, 2 dd, 3 ddd ...
    int derivativesResults[degree];
    int result;

    cout<<"Uwaga: wspolczynniki podajemy w kolejnosci od najwiekszej potegi x do najmniejszej!"<<endl;
    for(int i=0;i<degree+1;i++)
    {
        cout<<"Podaj wspolczynnik x^"<<degree-i<<": ";
        cin>>coefficients[i];
    }

    cout<<"Podaj punkt ktorego wartosci szukasz: ";
    cin>>searchedX;

    for(int i=0;i<degree+1;i++)
    {
        if(i==0)
            result=coefficients[i];
        else
        {
            result = result*searchedX+coefficients[i];
            //cout<<"Obliczenia: "<<result<<endl;
        }
    }

    cout<<"Wynik: "<<result<<endl;

    for(int i=0;i<degree;i++)
    {
        for(int j=0;j<degree-i;j++)
        {
            if(i==0)
            {
                if(j==0)
                {
                    derivatives[i][j]=coefficients[j+1]+(coefficients[0]*searchedX);
                    cout<<to_string(derivatives[i][j])+" = "+to_string(coefficients[j+1])+" + ("+to_string(coefficients[0])+"*"+to_string(searchedX)+")"<<endl;
                }
                else
                {
                    derivatives[i][j]=coefficients[j+1]+(derivatives[i][j-1]*searchedX);
                    cout<<to_string(derivatives[i][j])+" = "+to_string(coefficients[j+1])+" + ("+to_string(derivatives[i][j-1])+"*"+to_string(searchedX)+")"<<endl;
                }
            }
            else
            {
                if(j==0)
                {
                    derivatives[i][j]=derivatives[i-1][j]+(coefficients[j]*searchedX);
                    cout<<to_string(derivatives[i][j])+" = "+to_string(derivatives[i-1][j])+" + ("+to_string(coefficients[j+1])+"*"+to_string(searchedX)+")"<<endl;
                }
                else
                {
                    derivatives[i][j]=derivatives[i-1][j]+(derivatives[i][j-1]*searchedX);
                    cout<<to_string(derivatives[i][j])+" = "+to_string(derivatives[i-1][j])+" + ("+to_string(derivatives[i][j-1])+"*"+to_string(searchedX)+")"<<endl;
                }
            }
        }
    }

    //debug
    for(int i=0;i<degree;i++)
    {
        for(int j=0;j<degree-i;j++)
        {
            cout<<derivatives[i][j]<<"; ";
        }
        cout<<endl;
    }

    for(int i=0;i<degree+1;i++)
    {
        if(i==degree)
            derivativesResults[i]=coefficients[0]*silnia(i);
        else
            derivativesResults[i]=derivatives[i][degree-1-i]*silnia(i);
    }

    for(int i=0;i<degree+1;i++)
    {
        cout<<derivativesResults[i]<<"; ";
    }

    return 0;
}

