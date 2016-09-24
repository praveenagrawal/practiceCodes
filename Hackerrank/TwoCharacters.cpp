#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct pairBox
{
	char next;
	int count;
	bool stop = false;
	pairBox()
	{
		count = 0;
	}
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s.length()<2)
	{
		cout<<0;
		return 0;
	}
    std::vector<std::vector<pairBox> > charMap(26, vector<pairBox> (26));
    std::vector<char> stackChar;
    std::vector<int> stackcount;
    for(int i=0;i<n;i++)
	{
		int m = stackChar.size();
		bool found = false;
		for(int j=0;j<m;j++)
		{
			if(stackChar[j]!=s[i])
			{
				if(charMap[stackChar[j]-'a'][s[i]-'a'].count==0 && charMap[stackChar[j]-'a'][s[i]-'a'].stop==false && stackcount[j]==1)
				{
					charMap[stackChar[j]-'a'][s[i]-'a'].count++;
					charMap[s[i]-'a'][stackChar[j]-'a'].count++;
					charMap[stackChar[j]-'a'][s[i]-'a'].next=stackChar[j];
					charMap[s[i]-'a'][stackChar[j]-'a'].next=stackChar[j];
				}
				else if(charMap[stackChar[j]-'a'][s[i]-'a'].next==s[i] && charMap[stackChar[j]-'a'][s[i]-'a'].stop==false)
				{
					charMap[stackChar[j]-'a'][s[i]-'a'].count++;
					charMap[s[i]-'a'][stackChar[j]-'a'].count++;
					charMap[stackChar[j]-'a'][s[i]-'a'].next=stackChar[j];
					charMap[s[i]-'a'][stackChar[j]-'a'].next=stackChar[j];
				}
				else
				{
					charMap[stackChar[j]-'a'][s[i]-'a'].stop=true;
					charMap[s[i]-'a'][stackChar[j]-'a'].stop=true;
					charMap[stackChar[j]-'a'][s[i]-'a'].count=0;
					charMap[s[i]-'a'][stackChar[j]-'a'].count=0;
				}
			}
			else
			{
				found = true;
				stackcount[j]++;
			}
		}
		if(!found)
		{
			stackChar.push_back(s[i]);
			stackcount.push_back(1);
		}
	}
	pairBox maxBox = charMap[1][0];
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(charMap[i][j].count>maxBox.count)
				maxBox = charMap[i][j];
		}
	}
	if(maxBox.count>0)
		maxBox.count++;
	cout<<maxBox.count;
    return 0;
}