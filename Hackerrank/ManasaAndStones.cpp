#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T;
    cin>>T;
    while(T--)
    {
    	std::vector<int> result;
    	int n,a,b;
    	cin>>n>>a>>b;
    	if(a>b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		if(a!=b)
		{
			for(int i=0;i<n;i++)
				cout<<i*b+(n-i-1)*a<<" ";
		}
		else
			cout<<(n-1)*a;
		cout<<endl;
    }  
    return 0;
}
