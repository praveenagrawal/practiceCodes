#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct listCell
{
	int count=0;
	int location=-1;
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin>>s;
    int n = s.length();
    unsigned long long count = 0;
    std::vector< vector<int> > preList(n, vector<int>(26, 0));
    std::vector< vector<int> > postList(n, vector<int>(26, 0));
   	for(int i=1;i<n;i++)
	{
		for(int j=0;j<26;j++)
			preList[i][j]=preList[i-1][j];
		preList[i][s[i-1]-'a']++;
	//	for(int j=0;j<=i-1;j++)
	//		preList[i][s[j]-'a']++;
	}
	for(int i=n-2;i>=0;i--)
	{
		for(int j=0;j<26;j++)
			postList[i][j]=postList[i+1][j];
		postList[i][s[i+1]-'a']++;
	//	for(int j=n-1;j>i;j--)
	//		postList[i][s[j]-'a']++;
	}
	for(int i=1;i<n-2;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			if(s[j]==s[i])
			{
				for(int k=0;k<26;k++)
					count = (count + preList[i][k]*postList[j][k])%(1000000007);
			}
		}
	}
	cout<<count;
    return 0;
}
