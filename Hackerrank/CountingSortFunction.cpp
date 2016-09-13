#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct cellA
{
	int a=-1;
	string s;
};

void countingSort(vector<int> &A, vector<cellA> &B, std::vector<string> s, int M)
{
	std::vector<int> C(M,0);
	for(int i=0;i<A.size();i++)
		C[A[i]]++;
	for(int i=1;i<M;i++)
		C[i]+=C[i-1];

	for(int i=A.size()-1;i>=A.size()/2;i--)
	{
		B[C[A[i]]-1].a = A[i];
		B[C[A[i]]-1].s = s[i];
		C[A[i]]--;
	}
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    std::vector<int> A(n);
    std::vector<string> s(n);
    for(int i=0;i<n;i++)
	{
    	cin>>A[i];
    	cin>>s[i];
	}
    int M=100;
    std::vector<cellA> B(n);
    countingSort(A, B, s, M);
    for(int i=0;i<A.size();i++)
	{
		if(B[i].a>=0)
			cout<<B[i].s<<" ";
		else
			cout<<"- ";
	}
    return 0;
}
