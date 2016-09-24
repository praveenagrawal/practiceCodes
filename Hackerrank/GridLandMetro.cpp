#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct interval
{
	int c1;
	int c2;
};

struct train
{
	int r;
	std::vector<interval> vecTrain;
};

bool mycomp(interval a, interval b)
{   return a.c1 < b.c1; }

int main() {
    /* Enter your code here. Read input from STDIN. Prunsigned long long output to STDOUT */   
    unsigned long long n,m,k;
    cin>>n>>m>>k;
    std::vector<train> trains;
    unsigned long long count = m*n;
    for(int ci=0;ci<k;ci++)
	{
		train thisTrain;
		interval thisInterval;
		cin>>thisTrain.r>>thisInterval.c1>>thisInterval.c2;
		bool done = false;
		for(int cj=0;cj<trains.size();cj++)
		{
			if(trains[cj].r==thisTrain.r)
			{
				trains[cj].vecTrain.push_back(thisInterval);
				done = true;
				break;
			}
		}
		if(!done)
		{
			thisTrain.vecTrain.push_back(thisInterval);
			trains.push_back(thisTrain);
		}
	}
	for(int i=0;i<trains.size();i++)
	{
		sort(trains[i].vecTrain.begin(), trains[i].vecTrain.end(), mycomp);
		std::vector<interval> stackInterval;
		stackInterval.push_back(trains[i].vecTrain[0]);
		for(int j=1;j<trains[i].vecTrain.size();j++)
		{
			interval top = stackInterval[stackInterval.size()-1];
			if(trains[i].vecTrain[j].c2<top.c1 || trains[i].vecTrain[j].c1>top.c2)
				stackInterval.push_back(trains[i].vecTrain[j]);
			else if(trains[i].vecTrain[j].c2>top.c2)
				stackInterval[stackInterval.size()-1].c2 = trains[i].vecTrain[j].c2;
		}
		for(int j=0;j<stackInterval.size();j++)
		{
			count-= stackInterval[j].c2 - stackInterval[j].c1 + 1;
		}
	}
	cout<<count;
    return 0;
}
	