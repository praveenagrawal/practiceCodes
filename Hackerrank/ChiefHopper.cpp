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
    std::vector<int> h(n);
    for(int i=0;i<n;i++)
    	cin>>h[i];
    unsigned long long result = 0;

    for(int i=n-1;i>=0;i--)
    	result= (result+h[i])/2 + (result+h[i])%2;

    cout<<result;

    return 0;
}
