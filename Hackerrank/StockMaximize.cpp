#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
	{
		int n;
		cin>>n;
		std::vector<int> price(n);
		for(int i=0;i<n;i++)
			cin>>price[i];
		int maxL = 0;
		unsigned long long profit = 0;
		for(int i=n-1;i>=0;i--)
		{
			if(price[i]>maxL)
				maxL = price[i];
			profit+= maxL - price[i];
		}
		cout<<profit<<endl;
	}
    return 0;
}
