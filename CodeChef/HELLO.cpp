#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int U,N;
		float D;
		cin>>D>>U>>N;
		bool advantage = false;
		float newCostIndex = 0;
		float newCost = 0;
		for(int i =1;i<=N;i++)
		{
			int M,C;
			float R;
			cin>>M>>R>>C;
			if(newCost==0)
				newCost = (C+R*U*M)/M;
			if((C+R*U*M)/M <(D*U) && (C+R*U*M)/M<=newCost)
			{
				advantage = true;
				newCost = (C+R*U*M)/M;
				newCostIndex = i;
			}
		}
		if(advantage)
			cout<<newCostIndex<<endl;
		else
			cout<<0<<endl;	
	}
}