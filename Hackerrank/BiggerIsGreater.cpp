#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
	{
		string w;
		cin>>w;
		if(w.length()==1)
		{
			cout<<"no answer\n";
			continue;
		}
		int i,j;
		for(i=w.length()-1;i>0;i--)
		{
			if(w[i-1]<w[i])
				break;
		}
		if(i==0)
		{
			cout<<"no answer\n";
			continue;
		}
		for(j=w.length()-1;j>=i;j--)
		{
			if(w[j]>w[i-1])
			{
				char ch = w[j];
				w[j] = w[i-1];
				w[i-1] = ch;
				break;
			}
		}
		//sort(w.begin()+i, w.end());
		for(int j=0;j<(w.length()-i)/2;j++)
		{	
			char ch = w[j+i];
			w[j+i] = w[w.length()-j-1];
			w[w.length()-j-1] = ch;
		}
		cout<<w<<endl;
	}
    return 0;
}
