#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindome(string &s, int i, int j)
{
    for(int k=i, l=j;k<=l;k++,l--)
    {
        if(s[k]!=s[l])
            return false;
    }
    return true;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n = s.size();
        int i=0, j=n-1;
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                if(isPalindome(s, i+1, j))
                {
                    cout<<i<<endl;
                    break;
                }
                if(isPalindome(s, i, j-1))
                {
                    cout<<j<<endl;
                    break;
                }
                cout<<-1<<endl;
                break;
            }
            if(i>=j)
            {
                cout<<-1<<endl;break;
            }
        }
    }
    return 0;
}
