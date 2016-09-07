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


int main()
{
    long t;
    cin >> t;
    long start=3;
    long acc = 3;
    while(acc<t)
	{
		start*=2;
		acc+=start;
	}
	cout<<acc-t+1;

    return 0;
}
