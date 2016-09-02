#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    int area = 0, maxArea = 0;
    int i;
    cin>>N;
    std::vector<int> H(N);
    for(i =0;i<N;i++)
    	cin>>H[i];
    std::vector<int> stackH;
    i=0;
    while(i<N)
   	{
   		if(stackH.size()==0)

   			stackH.push_back(i++);
   		else if(H[i]>=H[stackH.back()])
   			stackH.push_back(i++);
   		else if(H[i]<H[stackH.back()])
   		{
   			while(H[stackH.back()]>H[i] && stackH.size()>0)
   			{
   				int temp = stackH.back();
   				stackH.pop_back();
   				area = H[temp]*(stackH.size()?(i-stackH.back()-1):i);
   				if(area>maxArea)
   					maxArea = area;
   			}
   		}
   	}
   	while(stackH.size()!=0)
   	{
   		int temp = stackH.back();
		stackH.pop_back();
		area = H[temp]*(stackH.size()?(i-stackH.back()-1):i);
		if(area>maxArea)
			maxArea = area;
   	}
   	cout<<maxArea<<endl;
    return 0;

}
