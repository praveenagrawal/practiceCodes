#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(std::vector<int> &A, int low, int high)
{
	unsigned long long sumA = 0, sum1=0;
	if(low==high)
		return 0;
	for(int i=low;i<=high;i++)
		sumA+=A[i];
	if(sumA%2!=0)
		return 0;
	int i;
	for(i=low;i<=high;i++)
	{
		sum1+=A[i];
		if(sum1==sumA/2)
			break;
		else if(sum1>sumA/2)
			return 0;
	}
	int p1 = partition(A, low, i);
	int p2 = partition(A, i+1, high);
	if(p1>p2)
		return p1+1;
	else
		return p2+1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
	{
		int n;
		cin>>n;
		std::vector<int> A(n);
		for(int i=0;i<n;i++)
			cin>>A[i];
		int points = 0;
		points = partition(A, 0, n-1);
		cout<<points<<endl;
	}
    return 0;
}
