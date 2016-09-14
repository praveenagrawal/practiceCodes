#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector <int> A(n);
        int sum = 0,suml=0;
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            sum+=A[i];
        }
        if(n==1)
            cout<<"YES\n";
        for(int i=1;i<n;i++)
        {
            suml+=A[i-1];
            if(suml==sum-suml-A[i])
            {
                cout<<"YES\n";
                break;
            }
            else if(suml>sum-suml-A[i])
            {
                cout<<"NO\n";
                break;
            }
        }
            
    }
    
    return 0;
}
