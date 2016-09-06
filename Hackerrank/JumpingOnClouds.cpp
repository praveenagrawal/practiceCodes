#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> c(n);
    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }
    int count = 0;
    int i=0;
    while(i<n-1)
    {
    	if(i+2<n)
		{
			if(c[i+2]==0)
			{
				count++;
				i+=2;
			}
			else
			{
				count++;
				i++;
			}
		}
		else if(i+1)
		{
			count++;
			i++;
		}

    }
    cout<<count;
    return 0;
}
