#include <iostream>
#include <vector>
using namespace std;
int M = 100000;
std::vector<bool> all(M,1);
std::vector<int> primes;

void sieve()
{
	all[0] = 0; all[1] = 0;
	for (int i=2;i*i<M;i++)
	{
		if(all[i])
		{
			for(int j=2*i;j<M;j+=i)
				all[j] = 0;
		}
	}
	for(int i =2;i<M;i++)
	{
		if(all[i])
			primes.push_back(i);
	}

}
int main()
{
	int t;
	cin>>t;
	sieve();
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		if(m<M)
		{
			for(int i =0;i<primes.size();i++)
			{
				if(primes[i]>n)
					break;
				if(primes[i]>=m)
					cout<<primes[i]<<endl;
			}
		}
		if(n>M)
		{
			if (m<M)
				m = M;
			std::vector<bool> check(n-m+1,1);
			for(int i = 0; i<primes.size();i++)
			{
				int low = (m/primes[i])*primes[i];
				if(low<m)
					low = low+primes[i];
				for(int j = low;j<n;j+= primes[i])
					check[j-m] = 0;
			}
			for(int i=m;i<n;i++)
			{
				if(check[i-m]==1)
					cout<<i<<endl;
			}
		}
		cout<<endl;
	}
}