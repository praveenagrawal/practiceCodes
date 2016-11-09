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
    int i=0;
    while(i<s.length())
	{
		if(s.length()>i+1 && s[i]==s[i+1])
		{
			s.erase(s.begin()+i);
			s.erase(s.begin()+i);
			if(i>0)
				i--;
		}
		else
			i++;
	}
	if(s.length()>0)
		cout<<s;
	else
		cout<<"Empty String";
    return 0;
}
