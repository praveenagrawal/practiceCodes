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
		int n = s.size();
		if(n%2!=0)
		{
			cout<<-1<<endl;
			continue;
		}
		std::vector<int> v(26,0);
		for(int i=n/2; i<=n-1;i++)
			v[s[i]-'a']++;
		int count = 0;
		for(int i=0;i<n/2;i++)
		{
			if(v[s[i]-'a']>0)
				v[s[i]-'a']--;
			else
				count++;
		}
		cout<<count<<endl;
	}
    return 0;
}
