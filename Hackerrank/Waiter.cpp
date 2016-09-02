#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int M = 1200;
std::vector<bool> allnum(M,1);
std::vector<int> primes;

void sieve()
{
	allnum[0] = 0; allnum[1] = 0;
	for (int i=2;i*i<M;i++)
	{
		if(allnum[i])
		{
			for(int j=2*i;j<M;j+=i)
				allnum[j] = 0;
		}
	}
	for(int i =2;i<M;i++)
	{
		if(allnum[i])
			primes.push_back(i);
	}

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,Q;
    cin>>N>>Q;
    vector <int> all(N);
    for(int i=0;i<N;i++)
    	cin>>all[i];
    vector <int> result;
    sieve();
    for(int i=0;i<=Q-1;i++)
   	{
   		vector <int> result;
   		int k =0;
		for(int j=all.size()-1;j>=0;j--)
		{
			if(all[j]%primes[i]==0)
			{
				cout<<all[j]<<endl;
				//result.push_back(all[j]);
				all.erase(all.begin()+j);
				j--;
			}
			else
			{
				int temp = all[j];
				all.erase(all.begin()+j);
				all.insert(all.begin()+k,all[j]);
				k++;
			}
		}
   	}
   	if(all.size()>0)
   	{
   		for(int i=0;i<all.size();i++)
   			cout<<all[i]<<endl;
   	}

    return 0;
}
