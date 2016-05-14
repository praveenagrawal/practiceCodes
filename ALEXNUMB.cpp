#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector <int> A(n);
		for(int i=0;i<n;i++)
			cin>>A[i];
		cout<<(n*(n-1))/2<<endl;
	}
}