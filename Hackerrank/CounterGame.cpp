#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

bool isPowerof2(ull n)
{
    return (n!=0)&&(!(n&(n-1)));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    while(t--)
    {
        ull n;
        cin>>n;
        int result = 1;     
        while(n!=1)
        {
            if(isPowerof2(n))
                n>>=1;
            else
            {
                ull temp = 1;
                temp<<=63;
                while(!(temp&n))
                    temp>>=1;
                n-=temp;
            }
            result*=-1;
        }
        if(result == 1)
            cout<<"Richard\n";
        else
            cout<<"Louise\n";
    }
    return 0;
}