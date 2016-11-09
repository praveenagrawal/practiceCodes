#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct order
{
	int orderNum;
	int orderTime;
	int processingTime;
	int finishTime;
};

bool myFunc(order l, order r)
{
	return l.finishTime<r.finishTime;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    std::vector<order> oList(n);
    for(int i=0;i<n;i++)
    {
    	cin>>oList[i].orderTime;
    	cin>>oList[i].processingTime;
    	oList[i].finishTime = oList[i].orderTime+oList[i].processingTime;
    	oList[i].orderNum = i+1;
    }
    stable_sort(oList.begin(), oList.end(), myFunc);
    for(int i=0;i<n;i++)
    	cout<<oList[i].orderNum<<" ";
    return 0;
}
