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
#include <unordered_map>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        long b;
        long w;
        cin >> b >> w;
        long x;
        long y;
        long z;
        cin >> x >> y >> z;
        long c1,c2,c3;
        c1 = b*x + y*w;
        if(x<y)
        {
            c2 = (b+w)*x + w*z;
            if(c2<c1)
                c1 = c2;
        }
        else if(x>y)
        {
            c3 = (b+w)*y + b*z;
            if(c3<c1)
                c1 = c3;
        }
        cout<<c1<<endl;
    }
    return 0;
}
