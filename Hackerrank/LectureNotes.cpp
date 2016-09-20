#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int can = false;
    for(int i=0;i<k;i++)
	{
		int id;
		cin>>id;
		if(s[id-1]=='0')
			can=true;
	}
	if(can)
		cout<<"YES\n";
	else
		cout<<"NO\n";
    return 0;
}
