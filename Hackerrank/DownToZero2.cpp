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

int main()
{
	int q;
	cin>>q;
	vector <int> all(M, 1);
    sieve(all);
    while(q--)
    {
    	std::vector<int> Q;
    	int N;
    	cin>>N;
    	Q.push_back(N);
    	Q.push_back(0);
    	int count;
    	while(Q.front()!=0)
    	{
    		int t = Q.front();
    		Q.erase(Q.begin());
    		count = Q.front();
    		Q.erase(Q.begin());
    		if(t==1)
    		{
    			Q.push_back(--t);
    			Q.push_back(count+1);
    		}
    		if(all[t])
    		{
    			t--;
    			Q.push_back(t);
    			Q.push_back(count+1);
    		}
    		else
    		{
    			if(t==4)
    			{
    				t/=2;
    				Q.push_back(t);
    				Q.push_back(count+1);
    			}
    			else
				{
    				for(int i=2;i<t/2;i++)
    				{
    					if(t%i==0)
    					{
    						Q.push_back(t/i);
    						Q.push_back(count+1);
    					}
    				}
    			}

    		}
    		count++;
    	}
    	cout<<Q[1]<<endl;

    }
}