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
    std::vector<int> A(1001, 0);
    std::vector<int> B(1001, 0);
    int result = 0;
    for(int i=0;i<n;i++)
    {
    	int t;
    	cin>>t;
    	A[t]++;
    }
    for(int i=0;i<n;i++)
    {
    	int t;
    	cin>>t;
    	B[t]++;
    }
    
    for(int i=1;i<=1000;i++)
	{
		result+= (A[i]>B[i])?B[i]:A[i];
	}
	if(result==n)
		result--;
	else
		result++;
	cout<<result;
    return 0;
}
