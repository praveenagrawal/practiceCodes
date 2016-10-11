#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    std::vector<int> count(10001, 0);
    for(int i=0;i<n;i++)
    {
    	int w;
    	cin>>w;
    	count[w]++;
    }
    int i=0;
    int result = 0;
    while(i<=10000)
	{
		if(count[i]>0)
		{
			result++;
			i+=5;
		}
		else
			i++;
	}
	cout<<result;
    return 0;
}
