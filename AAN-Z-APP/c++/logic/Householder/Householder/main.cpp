#include <cmath>
#include <iostream>

using namespace std;

template <typename T> int sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}

int main()
{
    int n;
    cout<<"Podaj wielkosc wektora: "<<endl;
    cin>>n;
    double inputVector[n];
    double resultVector[n];
    double t,a=0.0;

    for(int i =0;i<n;i++)
    {
        cout<<"Wprowadz "<<i<<" element wektora: "<<endl;
        cin>>inputVector[n];
        a+=inputVector[n]*inputVector[n];
    }
    a=sqrt(a);
    t=sgn(inputVector[0])*a;

    for(int i=0;i<n;i++)
    {
        if(i==0)
            resultVector[0] = 1*t;
        else
            resultVector[i] = 0;
    }


    cout<< "Wektor wyjsciowy: [";
    for(int i=0;i<n;i++)
    {
        cout<<resultVector[i]<<";";
    }
    cout<<"]"<<endl;

    return 0;
}
