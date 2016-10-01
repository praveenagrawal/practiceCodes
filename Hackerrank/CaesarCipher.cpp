#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    k = k%26;
    for(int i=0;i<n;i++)
	{
		if(s[i]>='a' && s[i]<='z')
			s[i] = 'a' + (s[i]-'a' + k)%('z'-'a' + 1);
		else if(s[i]>='A' && s[i]<='Z')
			s[i] = 'A' + (s[i]-'A' + k)%('Z'-'A' + 1);
	}
	cout<<s;
    return 0;
}
