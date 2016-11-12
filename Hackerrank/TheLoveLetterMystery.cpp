#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
	{
		string s;
		cin>>s;
		int result = 0;
		int n = s.size();
		for(int i=0;i<n/2;i++)
		{
			if(s[i]!=s[n-1-i])
				result+=abs(s[n-1-i]-s[i]);
		}
		cout<<result<<endl;
	}
    return 0;
}
