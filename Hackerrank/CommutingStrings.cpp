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
    int m;
    cin>>m;
    int count = 0;
    int group=1;
    int l = s.length();
	int i=0;
    while(i<l/2 && group<l)
	{
		if(s[i]==s[i+group])
			i+=group;
		else
		{
			i=0;
			group++;
			while(l%group!=0)
				group++;
		}
	}
	cout<<(m/group)%1000000007;
    return 0;
}
