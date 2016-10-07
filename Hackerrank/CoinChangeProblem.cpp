#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin>>n>>m;
    std::vector<int> coins(m);
    for(int i=0;i<m;i++)
    	cin>>coins[i];
	std::vector<unsigned long long> table(n+1,0);    
	table[0] = 1;
    for(int i=0;i<m;i++)
	{
		for(int j=coins[i];j<=n;j++)
		{
			table[j]+= table[j-coins[i]];
		}
	}
	cout<<table[n];
    return 0;
}
