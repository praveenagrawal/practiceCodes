#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct child
{
	int rating;
	int pos = 0;
	int candies = 1;
};

bool myfunc(child i, child j)
{
	return (i.rating < j.rating);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    std::vector<child> children(n);
    for(int i=0;i<n;i++)
	{
    	cin>>children[i].rating;
    	children[i].pos = i;
	}
	sort(children.begin(), children.end(), myfunc);
	std::vector<int> pos(n);
	for(int i=0;i<n;i++)
		pos[children[i].pos] = i;
	for(int i=0;i<n;i++)
	{
		int n1 = pos[children[i].pos-1];
		int n2 = pos[children[i].pos+1];
		if(children[i].pos>0 && children[i].pos<n-1)
		{
			if((children[n1].candies<=children[i].candies) && (children[n1].rating > children[i].rating))
				children[n1].candies = children[i].candies + 1;
			if((children[n2].candies<=children[i].candies) && (children[n2].rating > children[i].rating))
				children[n2].candies = children[i].candies + 1;
		}	
		else if(children[i].pos==0)
		{
			if((children[n2].candies<=children[i].candies) && (children[n2].rating > children[i].rating))
				children[n2].candies = children[i].candies + 1;
		}
		else if(children[i].pos==n-1)
		{
			if((children[n1].candies<=children[i].candies) && (children[n1].rating > children[i].rating))
				children[n1].candies = children[i].candies + 1;
		}
	}
	unsigned long long total = 0;
	for(int i=0;i<n;i++)
		total+= children[i].candies;
	cout<<total;
    return 0;
}
