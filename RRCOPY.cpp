#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int count = 0;
		vector <int> all(100001,0);
		for(int i=0;i<N;i++)
		{
			int a;
			cin>>a;
			all[a]++;
		}
		for(int i=0;i<100001;i++)
		{
			if(all[i]>0)
				count++;
		}
		cout<<count<<endl;
	}
}