#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void calculateMax(std::vector<int> &H, std::vector<unsigned long long> &P, std::vector<unsigned long long> &S, int n)
{
	unsigned long long sumH = 0, removeH = 0;
	for(int i=0;i<n;i++)
		sumH+= H[i];
	for(int i=0;i<n;i++)
	{
		S[i]+= i;
		P[i] = S[i]*(sumH - removeH);
		removeH+= H[i];
	}
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
	{
		int n;
		cin>>n;
		std::vector<int> H(n);
		for(int i=0;i<n;i++)
			cin>>H[i];
		sort(H.begin(),H.end());
		std::vector<unsigned long long> P(n,0);
		std::vector<unsigned long long> S(n,1);
		calculateMax(H, P, S, n);
		unsigned long long maxP = 0;
		for(int i=0;i<n;i++)
			maxP = (P[i]>maxP)?P[i]:maxP;
		cout<<maxP<<endl;
	}
    return 0;
}
