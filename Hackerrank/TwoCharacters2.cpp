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
    int len;
    cin >> len;
    string s;
    cin >> s;
    int maxLength = 0;
    for(int i=0;i<26;i++)
    {
        for(int j=i+1;j<26;j++)
        {
            int tempLength = 0;
            char next='A';
            int k;
            for(k=0;k<len;k++)
            {
                if(s[k]=='a'+i) 
                {
                    if(next=='A' || next=='a'+i)
                    {
                        tempLength++;
                        next = 'a'+j;
                    }
                    else
                        break;
                }
                else if (s[k]=='a'+j)
                {
                    if(next=='A' || next=='a'+j)
                    {
                        tempLength++;
                        next = 'a'+i;
                    }
                    else break;
                }
            }
            if(k==len && tempLength>maxLength && tempLength>1)
                maxLength = tempLength;
        }
    }
    cout<<maxLength;
    return 0;
}
