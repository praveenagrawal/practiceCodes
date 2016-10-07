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
		int n;
		cin>>n;
		std::vector<int> table(n+1,-1);
		table[0] = 1;
		table[1] = 1;
		if(n==2) table[2] = 1;
		if(n>=3)
		{
			table[2] = 1;
			table[3] = 1;
		}
		for(int i=4;i<=n;i++)
		{
			table[i] = table[i-1] + table[i-4];
		}
		std::vector<int> primes(table[n]+1, 1);
		for(int i=2;i*i<=table[n];i++)
		{
			if(primes[i]==1)
			{
				for(int j=2*i;j<=table[n];j+=i)
				{
					primes[j] = 0;
				}
			}
		}
		int count = 0;
		for(int i=2;i<=table[n];i++)
		{
			if(primes[i]==1)
				count++;
		}
		cout<<count<<endl;

	}
    return 0;
}
