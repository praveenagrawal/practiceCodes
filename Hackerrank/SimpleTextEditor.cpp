#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct operation
{
	int t;
	int length;
	string s;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s="";
    int Q;
    cin>>Q;
	std::vector<operation> pastOps;
    for(int i=0;i<Q;i++)
    {
    	int t;
    	cin>>t;
    	if(t==1)
    	{
    		string W;
    		cin>>W;
    		operation thisOp;
    		thisOp.t=1;
    		thisOp.length=W.length();
    		thisOp.s =  W;
    		pastOps.push_back(thisOp);
    		s = s+W;
    	}
    	else if(t==2)
    	{
    		int k;
    		cin>>k;
    		operation thisOp;
    		thisOp.t = 2;
    		thisOp.length = k;
    		thisOp.s = s.substr(s.length()-k, k);
    		pastOps.push_back(thisOp);
    		s.erase(s.length()-k, k);
    	}
    	else if(t==3)
    	{
    		int k;
    		cin>>k;
    		cout<<s[k-1]<<endl;
    	}
    	else if(t==4)
    	{
    		operation lastOp = pastOps.back();
    		pastOps.pop_back();
    		if(lastOp.t==1)
    			s = s.substr(0, s.length()-lastOp.length);
    		else if(lastOp.t==2)
    			s = s+lastOp.s;
    	}
    }

    return 0;
}
