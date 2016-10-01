#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,K;
    cin>>N>>K;
    std::vector<int> A(N);
    std::vector<int> pos(N+1);
    for(int i=0;i<N;i++)
	{
		cin>>A[i];
		pos[A[i]]=i;
	}
	if(K>=N)
	{
		for(int i=N;i>0;i--)
			cout<<i<<" ";
	}
	else
	{
		int count = 0;
		for(int i=0;i<N && count<K;i++)
		{
			if(A[i]!=N-i)
			{
				int temp = A[i];
				A[i]=N-i;
				A[pos[N-i]] = temp;
				pos[temp] = pos[N-i];
				pos[N-i] = i;
				count++;
			}
		}
		for(int i=0;i<N;i++)
			cout<<A[i]<<" ";
	}
    return 0;
}
