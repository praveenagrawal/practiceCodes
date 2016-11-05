#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
	int N, waiting=1;
	long long W,L,m=0;
	cin>>N>>W>>L;
	vector <long long> R(N);
	vector <long long> H(N);
	vector <long long> temp(N,0);
	int can = 1;
	for(int i=0;i<N;i++)
		cin>>H[i]>>R[i];
	
	long long min;
	if(H[0]<L)
	{
		temp[0] = ceil((L-H[0])/((long double)R[0]));
		min = temp[0];
	}
	else
		can = 0;
	for(int i=1;i<N && can == 1;i++)
	{
		if(H[i]<L)
			temp[i] = ceil((L-H[i])/((long double)R[i]));
		else
		{
			can = 0;
			break;
		}
		if(temp[i]<min)
			min = temp[i];
	}
	int step = 10;
	while(waiting)
	{
		unsigned long long sum = 0;
		for(int i=0;i<N;i++)
		{
			if(can && min!=0)
			{
				H[i]+=min*R[i];
				m=min;
			}
			if(H[i]>=L)
				sum+=H[i];
		}
		can = 0;
		if(sum>W)
		{
			if(step==1)
				waiting = 0;
			else
			{
				m-=step;
				for(int i=0;i<N;i++)
					H[i]-=step*R[i];
				step = 1;
			}

		}
		else if(sum==W)
			waiting = 0;
		else
		{
			m+=step;
			for(int i=0;i<N;i++)
				H[i]+=step*R[i];
		}

	}
	cout<<m;
}