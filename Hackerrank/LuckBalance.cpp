#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct contest
{
	int L;
	int T;
};

bool myFunc (contest l, contest r)
{
	return l.L> r.L;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, K;
    cin>>N>>K;
    std::vector<contest> cList(N);
    for(int i=0;i<N;i++)
		cin>>cList[i].L>>cList[i].T;
	sort(cList.begin(), cList.end(), myFunc);
	int count = 0;
	int result = 0;
	for(int i=0;i<N;i++)
	{
		if(cList[i].T==0)
			result+= cList[i].L;
		else
		{
			if(count<K)
			{
				result+= cList[i].L;
				count++;
			}
			else
			{
				result-= cList[i].L;
			}
		}
	}
	cout<<result;
    return 0;
}
