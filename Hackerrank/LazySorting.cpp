#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

unsigned long long factorial(int n)
{
	unsigned long long fact = 1;
	for(int i=2;i<=n;i++)
		fact*=i;
	return fact;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n;
	cin>>n;
	unsigned long long fact=1;
	fact = factorial(n);
	std::vector<int> P(n);
	std::vector<int> count(104,0);
	bool arranged = true;
	cin>>P[0];
	count[P[0]]++;
	for(int i=1;i<n;i++)
	{
		cin>>P[i];
		count[P[i]]++;
		if(P[i]<P[i-1])
			arranged = false;
	}
	for(int i=0;i<101;i++)
	{
		if(count[i]>1)
			fact/= (factorial(count[i]));
	}
	if(arranged)
		cout<<0;
	else
		cout<<fact;
	cout<<".000000";
    return 0;
}
