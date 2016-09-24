#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct train
{
	int r;
	int c1;
	int c2;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m,k;
    cin>>n>>m>>k;
    std::vector<train> vecTrain;
    unsigned long long count = m*n;
    for(int ci=0;ci<k;ci++)
	{
		train thisTrain;
		cin>>thisTrain.r>>thisTrain.c1>>thisTrain.c2;
		int amount = thisTrain.c2 - thisTrain.c1 + 1;
		vecTrain.push_back(thisTrain);
		for(int i=0;i<vecTrain.size()-1;i++)
		{
			if(vecTrain[i].r==thisTrain.r)
			{
				if(thisTrain.c1<=vecTrain[i].c1 && thisTrain.c2<=vecTrain[i].c2 && thisTrain.c2>=vecTrain[i].c1)
				{
					amount = (amount>(vecTrain[i].c1 - thisTrain.c1))?(vecTrain[i].c1 - thisTrain.c1):amount;
					thisTrain.c2 = vecTrain[i].c1-1;
				}
				else if(thisTrain.c1>=vecTrain[i].c1 && thisTrain.c2>=vecTrain[i].c2 && thisTrain.c1<=vecTrain[i].c2)
				{
					amount = (amount>(thisTrain.c2 - vecTrain[i].c2))?(thisTrain.c2 - vecTrain[i].c2):amount;
					thisTrain.c1 = vecTrain[i].c2+1;
				}
				else if(thisTrain.c1<=vecTrain[i].c1 && thisTrain.c2>=vecTrain[i].c2)
				{
					amount = (amount>(vecTrain[i].c1 - thisTrain.c1) + (thisTrain.c2 - vecTrain[i].c2))?((vecTrain[i].c1 - thisTrain.c1) + (thisTrain.c2 - vecTrain[i].c2)):amount;
				}
				else if(thisTrain.c1>=vecTrain[i].c1 && thisTrain.c2<=vecTrain[i].c2)
					amount = 0;
				else
					amount = thisTrain.c2 - thisTrain.c1 + 1;
			}
		}
		count-= amount;
	}
	cout<<count;
    return 0;
}
	