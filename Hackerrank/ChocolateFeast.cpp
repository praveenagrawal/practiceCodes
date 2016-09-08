#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        int count = 0;
        count = n/c;
        int wrappers = count;
        while(wrappers>=m)
    	{
    		count+= wrappers/m;
    		wrappers = wrappers - m*(wrappers/m) + wrappers/m;
    	}
    	cout<<count<<endl;
    }
    return 0;
}
