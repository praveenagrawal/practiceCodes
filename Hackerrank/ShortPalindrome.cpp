#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct listCell
{
	int count=0;
	std::vector<int> location;
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin>>s;
    int n = s.length();
    unsigned long long count = 0;
    std::vector< vector<listCell> > preList(n, vector<listCell>(26));
    std::vector< vector<listCell> > postList(n, vector<listCell>(26));
   	for(int i=1;i<n;i++)
	{
		for(int j=0;j<26;j++)
			preList[i][j]=preList[i-1][j];
		preList[i][s[i-1]-'a'].count++;
		preList[i][s[i-1]-'a'].location.push_back(i-1);
	}
	for(int i=n-2;i>=0;i--)
	{
		for(int j=0;j<26;j++)
			postList[i][j]=postList[i+1][j];
		postList[i][s[i+1]-'a'].count++;
		postList[i][s[i+1]-'a'].location.push_back(i+1);
	}
	for(int i=1;i<n-2;i++)
	{
		for(int j=0;j<postList[i][s[i]-'a'].location.size();j++)
		{
			for(int k=0;k<26;k++)
				count = (count + preList[i][k].count*postList[postList[i][s[i]-'a'].location[j]][k].count)%(1000000007);
		}
	}
	cout<<count;
    return 0;
}
