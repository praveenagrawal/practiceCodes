#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
	{
		ull n, k, b;
		cin>>n>>k>>b;
		ull minSum = (b*(b+1))/2;
		ull maxSum = ((k*(k+1))/2) - (((k-b)*(k-b+1))/2);
		if(n<minSum || n>maxSum)
		{
			cout<<-1;
			if(t!=0)
				cout<<endl;
			continue;
		}
		ull temp = n-minSum;
		int i;
		for(i=b;i>1;i--)
		{
			ull t2 = (temp<(k-(b-i)-i))?temp:k-(b-i)-i;
			cout<<i+t2<<" ";
			temp-=t2;
		}
		cout<<i+temp;
		if(t!=0)
			cout<<endl;
	}
    return 0;
}
