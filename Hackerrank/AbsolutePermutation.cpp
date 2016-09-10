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

int permuteA(vector<int> &a, int n, int k)
{
	if(k==0)
		return 1;
	else if(n%2==1)
		return -1;
	else if(n%k!=0)
		return -1;
	else
	{
		for(int i=1;i<=n-2*k +1;i+=2*k)
		{
			int c=1, j=i;
			while(c<=k)
			{
				int temp = a[j];
				a[j] = a[j+k];
				a[j+k] = temp;
				c++;j++;
			}			
		}
		return 1;
	}

}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        int k;
        cin >> n >> k;
        std::vector<int> a(n+1);
        for(int i=0;i<=n;i++)
        	a[i] = i;
        int r = permuteA(a, n, k);
        if(r==-1)
        	cout<<-1;
        else
        {
        	for(int i=1;i<=n;i++)
        		cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
