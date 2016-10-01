#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    std::vector<int> c(n);
    std::vector<int> pair(101,0);
    int count = 0;
    for(int i=0;i<n;i++)
	{
		cin>>c[i];
		pair[c[i]]++;
	}
	for(int i=0;i<101;i++)
		count+= pair[i]/2;
	cout<<count;
    return 0;
}
