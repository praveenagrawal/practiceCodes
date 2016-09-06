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
    string s;
    cin >> s;
    long n;
    cin >> n;
    long long countA=0, c2=0;
    for(int i=0;i<s.length();i++)
   	{
   		if(s[i]=='a')
   			countA++;
   	}
   	int temp = n % s.length();
   	for(int i=0;i<temp;i++)
   	{
   		if(s[i]=='a')
   			c2++;
   	}
	countA = (n/s.length())*countA + c2;
   	cout<<countA<<endl;
    return 0;
}
