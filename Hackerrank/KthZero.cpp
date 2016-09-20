#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin>>n>>m;
    std::vector<int> A(n);
    std::vector<int> zeroIndex;
    for(int i=0;i<n;i++)
	{
		cin>>A[i];
		if(A[i]==0)
			zeroIndex.push_back(i);
	}
	for(int i=0;i<m;i++)
	{
		int q;
		cin>>q;
		if(q==1)
		{
			int k;
			cin>>k;
			if(k<=zeroIndex.size())
				cout<<zeroIndex[k-1]<<endl;
			else
				cout<<"NO"<<endl;
		}
		else
		{
			int p,x;
			cin>>p>>x;
			if((A[p]!=0 && x!=0)||(A[p]==0 && x==0))
				A[p]=x;
			else if(A[p]!=0 && x==0)
			{
				A[p]=x;
				int j=0;
				for(j=0;j<zeroIndex.size();j++)
				{
					if(p>zeroIndex[j])
						break;
				}
				if(j==zeroIndex.size())
					zeroIndex.push_back(p);
				else
				{
					j--;
					zeroIndex.insert(zeroIndex.begin()+j, p);
				}
			}
			else if(A[p]==0 && x!=0)
			{
				A[p]=x;
				int j;
				for(j=0;j<zeroIndex.size();j++)
				{
					if(p==zeroIndex[j])
						break;
				}
				zeroIndex.erase(zeroIndex.begin()+j);
			}
		}
	}
    return 0;
}
