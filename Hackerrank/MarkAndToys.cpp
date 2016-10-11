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
    std::vector<int> price(n);
    for(int i=0;i<n;i++)
    	cin>>price[i];
    sort(price.begin(), price.end());
    int count = 0;
    unsigned long long amt = 0;
    for(int i=0;i<n;i++)
	{
		amt+= price[i];
		if(amt<=k)
			count++;
		else
			break;
	}
	cout<<count;
    return 0;
}
