#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
	unsigned long long N;
	cin>>N;
	vector <unsigned long long> C(N);
	unsigned long long sum = 0;
	for(int i=0;i<N;i++)
	{
		cin>>C[i];
		sum+=C[i];
	}
	if((N*(N+1))/2 == sum)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}