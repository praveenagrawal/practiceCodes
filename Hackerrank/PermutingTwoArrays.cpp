#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool myFunc(int a, int b)
{
	return a>b;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin>>q;
    while(q--)
	{
		int n,k;
		cin>>n>>k;
		std::vector<int> A(n);
		std::vector<int> B(n);
		for(int i=0;i<n;i++)
			cin>>A[i];
		for(int i=0;i<n;i++)
			cin>>B[i];
		sort(A.begin(), A.end());
		sort(B.begin(), B.end(), myFunc);
		bool possible = true;
		for(int i=0;i<n;i++)
		{
			if(A[i]+B[i]<k)
			{
				possible = false;
				break;
			}
		}
		if(possible)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
    return 0;
}
