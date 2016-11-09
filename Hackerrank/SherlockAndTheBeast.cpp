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
    	int n;
    	cin>>n;
    	if(n<3)
		{
			cout<<-1<<endl;
			continue;
		}
		int done = false;
		for(int i=0;i<=n;i++)
		{
			if((n-i)%3==0 && i % 5 ==0)
			{
				for(int j=0;j<(n-i);j++)
					cout<<5;
				for(int j=0;j<i;j++)
					cout<<3;
				done = true;
				break;
			}
		}
		if(!done)
			cout<<-1;
		cout<<endl;
    }
    return 0;
}
