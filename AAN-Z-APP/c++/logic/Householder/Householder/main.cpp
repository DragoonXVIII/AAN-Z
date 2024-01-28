#include <cmath>
#include <iostream>

using namespace std;

double sgn(double a)
{
    if(a>0.0)
        return 1.0;
    else if(a<0.0)
        return (-1.0);
    else
        return 0.0;
}

int main()
{
    int n;
    cout<<"Podaj wielkosc wektora: "<<endl;
    cin>>n;
    double inputVector[n];
    double resultVector[n];
    double a=0.0,s,t;

    for(int i=0;i<n;i++)
    {
        cout<<"Wprowadz "<<i<<" element wektora: "<<endl;
        cin>>inputVector[i];
        a+=inputVector[i]*inputVector[i];
    }
    //cout<<"vector[0]: "<<inputVector[0]<<endl;
    a = sqrt(a);
    s = sgn(inputVector[0]);
    t = (-1)*s*a;
    //cout<<" a: "<<a<<" s: "<<s<<" t: "<<t<<endl;

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
