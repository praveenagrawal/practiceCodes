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
		std::vector<int> A(n);
		for(int i=0;i<n;i++)
			cin>>A[i];
		int count = 0;
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(A[i]>A[j])
					count++;
			}
		}
		if(count%2==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
    return 0;
}
