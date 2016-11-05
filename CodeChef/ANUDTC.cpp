#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		if(360%N==0)
			cout<<"y ";
		else
			cout<<"n ";
		if(N<=360)
			cout<<"y ";
		else
			cout<<"n ";
		if(360-(N*(N-1))/2.0 >= N)
			cout<<"y";
		else
			cout<<"n";
		cout<<endl;
	}
}