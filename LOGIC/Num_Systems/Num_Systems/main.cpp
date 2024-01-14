#include <algorithm>
#include <iostream>

using namespace std;

/*string NumericalSystemSwap_DtoT10_N(int number, int base)
{
    if(number==0)
        return "0";
    string result = "";

    while(number>0)
    {
        int remainder = number % base;
        result+=to_string(remainder);
        number/=base;
    }

    reverse(result.begin(), result.end());
    return result;
}*/

string NumericalSystemSwap_DtoT16_N(int number, int base)
{
    if(number==0)
        return "0";
    string result = "";

    while(number>0)
    {
        int remainder = number%base;
        if(remainder < 10)
            result+=to_string(remainder);
        else
        {
            char numberChar = remainder + 55;
            result+=to_string(numberChar);
        }
        number/=base;
    }
    reverse(result.begin(), result.end());

    return result;
}

int NumericalSystemSwap_T16toD_N(string number, int base)
{
    if(number=="0")
        return 0;
    int result = 0, power=1, hlpvar;

    for(int i=0; i<int(number.length());i++)
    {
        if(number[number.length()-i-1] >= '0' && number[number.length()-i-1] <= '9')
            hlpvar = number[number.length()-i-1]-'0';
        else
            hlpvar = number[number.length()-i-1] - 55;
        result += hlpvar*power;
        power *= base;
    }

    return result;
}

int main()
{
    int a;
    string b;
    cin>>a;
    cout<<NumericalSystemSwap_DtoT16_N(a,7)<<endl;
    cin>>b;
    cout<<NumericalSystemSwap_T16toD_N(b,7)<<endl;
    return 0;
}
