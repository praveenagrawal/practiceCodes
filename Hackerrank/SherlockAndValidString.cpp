#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool checkEqualF(std::vector<int> &A, int k)
{
	int prev = -1;
	for(int i=0;i<26;i++)
	{
		if(A[i]>0 && i!=k)
		{
			if(prev==-1)
				prev = A[i];
			else if(A[i]!=prev)
				return 0;
		}
	}
	return 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin>>s;
    vector <int> A(26,0);
    int n = s.size();
    for(int i=0;i<n;i++)
    	A[s[i]-'a']++;
	int count = 0;
	for(int i=0;i<26;i++)
	{
		if(checkEqualF(A, -1))
		{
			cout<<"YES";
			return 0;
		}
	}
	for(int i=0;i<26;i++)
	{
		if(A[i]>0 && checkEqualF(A,i))
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
    return 0;
}
