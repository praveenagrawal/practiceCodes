#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
	int N,K;
	cin>>N>>K;
	std::vector<bool> status(N,false);
	int total = 0;
	for(int i=0;i<K;i++)
	{
		char s[9];
		scanf("%s",s);
		if(strcmp(s,"CLOSEALL")==false)
		{
			for(int i = 0;i<N;i++)
				status[i] = false;
			total = 0;
		}
		else
		{
			int num;
			scanf("%d", &num);
			status[num-1] = !status[num-1];
			if(status[num-1])
				total++;
			else
				total--;
		}
		cout<<total<<endl;		
	}
}