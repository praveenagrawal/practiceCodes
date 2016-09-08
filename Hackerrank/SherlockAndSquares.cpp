#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int temp = sqrt(a);
        int count =0;
        for(int i=temp;i*i<=b;i++)
        {
            if(i*i>=a && i*i<=b)
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
