#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    std::vector<int> A(n);
    std::vector<int> diff(n-1);
    for(int i=0;i<n;i++)
    	cin>>A[i];			
    int p,q;
    cin>>p>>q;
    sort(A.begin(), A.end());
    for(int i=1;i<n;i++)
    	diff[i-1] = abs(A[i]-A[i-1]);
    int maxD = 0;
    int M;
    if(A[0]>=p)
	{
		maxD = abs(A[0]-p);
		M = p;
	}
	if(A[n-1]<=q && maxD<abs(A[n-1]-q))
	{
		maxD = abs(A[n-1]-q);
		M = q;
	}
    for(int i=0;i<n-1;i++)
	{
		if(A[i]>=p && A[i+1]<=q)
		{
			if(diff[i]/2>maxD)
			{
				maxD = diff[i]/2;
			 	M = A[i]+diff[i]/2;
			}
		}
		else if(A[i]>=p && A[i+1]>=q && A[i]<=q)
		{
			int temp;
			if(A[i]+diff[i]/2<=q)
				temp = A[i]+diff[i]/2;
			else
				temp = q;
			if(maxD<abs(temp-A[i]))
			{
				maxD = abs(temp-A[i]);
				M = temp;
			}
		}
		else if(p>=A[i] && q>=A[i+1] && p<=A[i+1])
		{
			int temp;
			if(A[i]+diff[i]/2>=p)
				temp = A[i]+diff[i]/2;
			else
				temp = p;
			if(maxD<abs(A[i+1]-temp))
			{
				maxD = abs(A[i+1]-temp);
				M = temp;
			}
		}
	}
	cout<<M;
    return 0;
}
