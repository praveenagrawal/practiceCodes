#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin>>s;
    int n = s.length();
    unsigned long long count = 0;
    std::vector< vector<int> > preList(n, vector<int>(26, 0));
    std::vector< vector<int> > postList(26, vector<int>(26, 0));
   	for(int i=1;i<n;i++)
	{
		for(int j=0;j<26;j++)
			preList[i][j]=preList[i-1][j];
		preList[i][s[i-1]-'a']++;
	} 
	postList[s[n-2]-'a'][s[n-1]-'a']++;
	for(int i=n-3;i>=1;i--)
	{
		for(int j=0;j<26;j++)
		{
			for(int k=0;k<26;k++)
			{
				if(postList[j][k]!=0)
				{
					postList[s[i]-'a'][j]++;
					postList[s[i]-'a'][k]++;
				}
			}
		}
	}
	for(int i=1;i<n-3;i++)
	{	
		for(int k=0;k<26;k++)
			count = (count + preList[s[i]][k]*postList[s[i]-'a'][k])%(1000000007);
		for(int j=0;j<26;j++)
		{
			if(postList[s[i+1]-'a'][j]>0)
				postList[s[i+1]-'a'][j]--;
		}
	}
	cout<<count;
    return 0;
}