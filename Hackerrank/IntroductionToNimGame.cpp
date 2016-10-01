#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int g;
    cin>>g;
    while(g--)
	{
		int n;
		cin>>n;
		std::vector<int> s(n);
		for(int i=0;i<n;i++)
			cin>>s[i];
		int result = s[0];
		for(int i=1;i<n;i++)
			result = result^s[i];
		if(!result)
			cout<<"Second\n";
		else
			cout<<"First\n";
	}
    return 0;
}
