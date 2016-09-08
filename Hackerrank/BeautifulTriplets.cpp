#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,d;
    cin>>n>>d;
    int M = 20001;
    std::vector<int> a(n);
    std::vector<bool> status(M,0);
    int max = 0;
    for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(!status[a[i]])
			status[a[i]]=true;
		if(a[i]>max)
			max = a[i];
	}
	if(max==M-1)
		max = max-d;
	int count = 0;
	for(int i=0;i<max;i++)
	{
		if(status[i] && status[i+d] && status[i+2*d])
			count++;
	}
	cout<<count;
    return 0;
}
