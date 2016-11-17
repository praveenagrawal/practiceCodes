#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

ull diagonalSum(int n)
{
	if(n==1)
		return 1;
	ull count = 1;
	ull M = (ull)n * n; 
	ull currentNum = M;
	ull sumD = M;
	int l = n-1;
	int direction = 3;	// 1-> right , 2-> down, 3-> left, 4->up
	while(l!=0)
	{
		if(direction==1)
		{
			currentNum-= l;
			direction = 4;
			sumD+=currentNum;
		}
		else if(direction==2)
		{
			currentNum-= l;
			direction = 1;
			sumD+=currentNum;
		}
		else if(direction==3)
		{
			currentNum-= l;
			direction = 2;
			sumD+=currentNum;
		}
		else
		{
			currentNum-=l;
			l-=2;
			direction = 3;
			sumD+=currentNum;
		}
	}
	return sumD;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
	{
		int n;
		cin>>n;
		cout<<diagonalSum(n)<<endl;
	}
    return 0;
}
