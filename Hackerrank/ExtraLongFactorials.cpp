#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    std::vector<int> bigInt;
    int t = n;
    while(t!=0)
	{
		bigInt.push_back(t%10);
		t/=10;
	}
	for(int i=1;i<n;i++)
	{
		int c=0, t;
		for(int j=0;j<bigInt.size();j++)
		{
			t = bigInt[j]*i + c;
			bigInt[j] = t%10;
			c = t/10;
		}
		while(c!=0)
		{
			bigInt.push_back(c%10);
			c/=10;
		}
	}
	for(int i=bigInt.size()-1;i>=0;i--)
		cout<<bigInt[i];
    return 0;
}
