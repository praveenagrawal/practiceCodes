#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;
    std::vector<int> old(N);
    std::vector<int> next;
    int days = 0;
    int dead = 0;
    cin>>old[0];
    next.push_back(old[0]);
    for(int i=1;i<N;i++)
    {
    	cin>>old[i];
    	if(old[i]<=old[i-1])
    		next.push_back(old[i]);
    	else
    		dead++;
    }
    if(dead>0)
    	days++;
    while(dead!=0)
    {
    	dead = 0;
    	old = next;
    	next.clear();
    	next.push_back(old[0]);
    	for(int i=1;i<old.size();i++)
    	{
    		if(old[i]<=old[i-1])
    			next.push_back(old[i]);
	    	else
    			dead++;
    	}
    	if(dead>0)
    		days++;
    }
    cout<<days<<endl;
    

    return 0;
}

