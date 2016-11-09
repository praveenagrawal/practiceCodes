#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N, count = 0;
		cin>>N;
		vector <string> A(N);
		vector <string> mirrors(N);
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			string s = "";
			string temp = A[i];
			int j;
			for(j=N-1;j>=0;j--)
			{
				if(temp[j]=='.')
					s+='1';
				else
					break;
			}
			for(int k = j;k>=0;k--)
				s = '0'+s;
			mirrors[i]=s;
		}
		for(int i=0;i<N;i++)
		{
			string s = mirrors[i];
			for(int j = N-1; j>=0; j--)
			{
				if(s[j]=='1')
				{
					int stop = 0;
					for(int k = i;k<N;k++)
					{
						string temp = mirrors[k];
						if(temp[j]!='1')
						{
							stop = 1;
							break;
						}
					}
					if(stop==0)
						count++;
				}
			}
		}
		cout<<count<<endl;
	}
}