#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string s;
    getline(cin,s);
    vector <int> count(26,0);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a' && s[i]<='z')
            count[s[i]-'a']++;
        else if(s[i]>='A' && s[i]<='Z')
            count[s[i]-'A']++;
    }
        
    bool pangram = true;
    for(int i=0;i<26;i++)
    {
        if(count[i]==0)
        {
            pangram = false;
            break;
        }
    }
    if(pangram)
        cout<<"pangram";
    else
        cout<<"not pangram";
    return 0;
}
