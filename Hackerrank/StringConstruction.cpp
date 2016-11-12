#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef std::vector<int> vi;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
	{
		string s;
		cin>>s;
		vi A(26, 0);
		int n = s.size();
		for(int i=0;i<n;i++)
			A[s[i]-'a']++;
		int count = 0;
		for(int i=0;i<26;i++)
			count+=(A[i]>0)?1:0;
		cout<<count<<endl;
	}

    return 0;
}
