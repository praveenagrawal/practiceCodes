#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    cin>>n>>k;
    std::vector<int> t(n);
    for(int i=0;i<n;i++)
    	cin>>t[i];
    int count = 0;
    int pgNum = 1;
    for(int i=0;i<n;i++)
	{
		for(int j=1;j<=t[i];j+=k)
		{
			if(j<=pgNum && (j+k-1>=pgNum && (j+k-1<=t[i] || t[i]>=pgNum) ))
				count++;
			pgNum++;
		}
	}
	cout<<count;
    return 0;
}
