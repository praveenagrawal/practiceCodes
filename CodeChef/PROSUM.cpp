#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		vector<int> A(N);
		long long count = 0, count2=0;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			if(A[i]==2)
				count2++;
			else if(A[i]!=0 && A[i]!=1)
				count++;
		}
		cout<<(count*(count-1))/2 + count2*count<<endl;
	}
}