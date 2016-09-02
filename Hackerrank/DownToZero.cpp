#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int M = 1000000;
void sieve(vector <int> &all)
{
    all[0] = 0; all[1] = 0;
    for(int i=2;i*i<M;i++)
    {
        if(all[i]==1)
        {
            for(int j=2*i;j<M;j+=i)
                all[j]=0;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int Q;
    cin>>Q;
    vector <int> all(M, 1);
    sieve(all);
    vector <int> results(M+1,-1);
    results[0] = 0; results[1] = 1;
    while(Q--)
    {
        int count = 0;
        int N;
        cin>>N;
        if(results[N]>=0)
            cout<<results[N]<<endl;
        else
        {
            int t=N;
            while(t!=0)
            {
                cout<<t<<"    fkfoekeokfef\n";
                if(all[t])
                {
                    t--;
                    count++;
                }
                cout<<t<<"    fkfoekeokfef\n";
                if(results[t]>=0)
                {
                    count+=results[t];
                    break;
                }
                else
                {
                    for(int i=2;i<=t/2;i++)
                    {
                        if(t%i==0)
                        {
                            count++;
                            t/=i;
                            break;
                        }
                    }
                }
                cout<<t<<"    fkfoekeokfef\n";
            }
            results[N] = count;
            cout<<results[N]<<endl;
        }
    }
    return 0;
}