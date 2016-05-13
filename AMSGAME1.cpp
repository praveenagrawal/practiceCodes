#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	if(a==0)
		return b;
	else if(b==0)
		return a;
	else
		gcd(b, a%b);
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector <int> A(N);
		for(int i=0;i<N;i++)
			cin>>A[i];
		if(N==1)
		{
			cout<<A[0]<<endl;
			continue;
		}
		int v = gcd(A[0],A[1]);
		for(int i=2;i<N;i++)
		{
			v = gcd(v, A[i]);
		}
		cout<<v<<endl;
	}
}

/*
//TIME LIMIT EXCEEDED. Obviously
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector <int> A(N);
		for(int i=0;i<N;i++)
			cin>>A[i];
		bool play = true;
		while(play)
		{
			for(int i=1;i<N;i++)
			{
				if(A[0]!=A[i])
				{
					if(A[0]>A[i])
						A[0]-=A[i];
					else
						A[i]-=A[0];
					break;
				}
				else if(i==N-1)
				{
					cout<<A[0]<<endl;
					play=false;
				}
			}
		}
	}
}
*/

/*
//TIME LIMIT EXCEEDED Again
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector <int> A(N);
		for(int i=0;i<N;i++)
			cin>>A[i];
		bool play = true;
		int max, min;
		while(play)
		{
			max = 0;min = 0;
			for(int i=1;i<N;i++)
			{
				if(A[i]>A[max])
					max = i;
				if(A[i]<A[min])
					min = i;
			}
			if(A[max]!=A[min])
				A[max]-=A[min];
			else
			{
				play = false;
				cout<<A[min]<<endl;
			}
		}
	}
}
*/