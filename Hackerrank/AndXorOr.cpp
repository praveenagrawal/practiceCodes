#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;
    std::vector<int> A(N);
    std::vector<int> sortA(N);
    for(int i=0;i<N;i++)
	{
    	cin>>A[i];
    	sortA[i] = i;
	}
    for(int i=0;i<N-1;i++)
    {
    	int min = A[sortA[i]];
    	for(int j=i+1;j<N;j++)
    	{
    		if(A[sortA[j]]<min)
    		{
    			min = A[sortA[j]];
    			int temp  = sortA[j];
    			sortA[j] = sortA[i];
    			sortA[i] = temp;
    		}
    	}
    }
    int maxVal =0;
    for(int i=0;i<N-1;i++)
    {
    	for(int j=i+1;j<N;j++)
    	{
    		int k, m1, m2;
    		for(k=0;k<N;k++)
    		{
    			if(sortA[k]>=i && sortA[k]<=j)
    			{
    				m1 = A[sortA[k]];
    				break;
    			} 
    		}
    		for(int l=k+1;k<N;k++)
    		{
    			if(sortA[l]>=i && sortA[l]<=j)
    			{
    				m2 = A[sortA[l]];
    				break;
    			} 
    		}
    		int temp = (((m1 & m2)^(m1 | m2)) & (m1 ^ m2));
    		if(temp>maxVal)
    			maxVal = temp;
    	}
    }
    cout<<maxVal;
    return 0;
}
