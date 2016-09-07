#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin>>T;
    while(T--)
	{
		int N, M, S;
		cin>>N>>M>>S;
		M = (M>N)?M%N:M;
		cout<<((S+M-1)>N?(S+M-1)%N:(S+M-1))<<endl;
	}
    return 0;
}
