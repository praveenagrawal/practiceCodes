#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int k;
    cin>>k;
    std::vector<int> A(n);
    for(int i=0;i<n;i++)
    	cin>>A[i];
    sort(A.begin(), A.end());
    int unfairness = INT_MAX;
    for(int i=0;i<=n-k;i++)
	{
		if(A[i+k-1] - A[i] < unfairness)
			unfairness = A[i+k-1] - A[i];
	}
	cout<<unfairness;
    return 0;
}
