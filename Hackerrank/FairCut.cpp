#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

//WRONG ANSWER
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n,k;
	cin>>n>>k;
	std::vector<int> a(n);
	std::vector<int> b(k);
	//std::vector<int> c(n-k);
	int value = 0;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(), a.end());
	int i = 0;
	while(i!=k)
	{

		if(n%2==1)
		{
			b[i] = a[n/2];
			a.erase(a.begin()+n/2);

		}
		else
		{
			int s1=0, s2=0;
			for(int j=0;j<n;j++)
			{
				s1+=abs(a[j]-a[n/2]);
				s2+=abs(a[j]- a[n/2 -1]);
			}
			if(s1<s2)
			{
				b[i] = a[n/2];
				a.erase(a.begin()+n/2);
			}
			else
			{
				b[i] = a[n/2 -1];
				a.erase(a.begin()+n/2 -1);
			}
		}
		i++;
		n--;
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<a.size();j++)
		{
			value+= abs(b[i]-a[j]);
		}
	}
	cout<<value;
    return 0;
}
