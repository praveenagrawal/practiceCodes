#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,K;
		cin>>N>>K;
		vector <unsigned long long> A(N), B(N);
		unsigned long long profit = 0;
		for(int i=0;i<N;i++)
			cin>>A[i];
		for(int i=0;i<N;i++)
		{
			cin>>B[i];
			unsigned long long temp = (K/A[i])*B[i];
			if(temp>profit)
				profit = temp;
		}
		cout<<profit<<endl;
	}
}