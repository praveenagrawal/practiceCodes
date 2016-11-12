#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int p;
    cin>>p;
    while(p--)
	{
		string a, b;
		cin>>a>>b;
		int n1 = a.size(), n2 = b.size();
		std::vector<int> A(26,0), B(26,0);
		bool result = false;
		for(int i=0;i<n1;i++)
			A[a[i]-'a']++;
		for(int i=0;i<n2;i++)
			B[b[i]-'a']++;
		for(int i=0;i<26;i++)
		{
			if(A[i]>0 && B[i]>0)
			{
				result = 1;
				break;
			}
		}
		if(result)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
    return 0;
}
