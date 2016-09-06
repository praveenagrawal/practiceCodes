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
    std::vector<int> A(n);
    std::vector<int> R(k);
    int count=0;
    for(int i=0;i<n;i++)
	{
   		cin>>A[i];
   		R[A[i]%k]++;
	}
	if(R[0])
		count++;
	int l;
	if(k%2==0)
	{
		count++;
		l=k/2;
	}
	else
		l=k/2 + 1;
	for(int i=1;i<l;i++)
	{
		count+= max(R[i], R[k-i]);
	}
	cout<<count;


    return 0;
}
