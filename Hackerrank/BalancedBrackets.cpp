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
#include <cstring>
#include <fstream>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        string s;
        cin >> s;
        int len = s.length();
        if(len%2==1)
        {
            cout<<"NO\n";
            continue;
        }
        vector <char> open;
        bool balanced = true;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='{' || s[i]=='[' || s[i]=='(')
                open.push_back(s[i]);
            else if(s[i]=='}' || s[i]==']' || s[i]==')')
            {
                if(open.size()>0)
                {
                    char ch = open.back();
                    open.pop_back();
                    if(!(s[i]=='}' && ch=='{' || s[i]==']' && ch=='[' || s[i]==')' && ch=='('))
                    {
                        balanced = false;
                        break;
                    }
                }
                else
                {
                    balanced = false;
                    break;
                }
            }
        }
        if(balanced && open.size()==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

