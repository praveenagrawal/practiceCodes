#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N,Q;
	cin>>N>>Q;
	vector<string> media(N), extension(N);
	for(int i=0;i<N;i++)
		cin>>extension[i]>>media[i];
	while(Q--)
	{	
		string file;
		cin>>file;
		string temp = "";
		bool extensionFound = 0;
		int done=0;
		for(int i= file.length()-1;i>=0;i--)
		{
			if(file[i]=='.')
				break;
			temp = file[i]+temp;
			if(i==0)
			{
				cout<<"unknown"<<endl;
				done=1;
				break;
			}
		}
		if(done)
			continue;
		for(int i=0;i<N;i++)
		{
			if(temp==extension[i])
			{
				cout<<media[i]<<endl;
				extensionFound = 1;
				break;
			}
		}
		if(extensionFound==0)
			cout<<"unknown"<<endl;
	}
}