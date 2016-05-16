#include <iostream>
#include <stdio.h>
using namespace std;	
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string time1,time2;
		int dist;
		int h1,h2,m1,m2,interval;
		scanf("%d:%d", &h1,&m1);
		scanf("%d:%d", &h2,&m2);
		cin>>dist;
		float reqTime = 0;
		if(m1>=m2 && h1>=h2)
			interval = (m1-m2)+60*(h1-h2);
		else if(m1<m2 && h1>h2)
			interval = (60-m2+m1)+60*(h1-h2-1);
		else if(h1<h2)
			interval = (60-m1+m2)+60*(24-h1-1+h2);
		printf("%.1lf ", (double)(interval+dist));
		if(interval>=2*dist)
			reqTime = interval;
		else
			reqTime = dist + (interval)/2.0;
		printf("%.1lf\n", reqTime);
	}
}