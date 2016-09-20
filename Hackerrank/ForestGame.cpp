#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int cost;
	int parent;
	bool status = true; //not deleted
	std::vector<int> child;
	node(){
		parent = -1;
		status = true;
	}

};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    std::vector<int> cost(n);
    unsigned long long totalPenalty = 0;
    for(int i=0;i<n;i++)
	{
    	cin>>cost[i];
    	totalPenalty+= cost[i];
	}
    vector<node> tree(n);
	int parent;
	for (int i = 1; i < n; ++i)
	{
		cin>>parent;
		parent--;
		tree[i].parent=parent;
		tree[parent].child.push_back(i);
	}
	unsigned long long penalty = 0;
	std::vector<int> stackTree;
	stackTree.push_back(0);
	while(stackTree.size()!=0)
	{
		int maxNode = 0;
		for(int i=0;i<stackTree.size();i++)
		{
			if(cost[stackTree[i]]>cost[stackTree[maxNode]])
				maxNode = i;
		}
		int node = stackTree[maxNode];
		stackTree.erase(stackTree.begin()+maxNode);
		tree[node].status = false;
		totalPenalty-=cost[node];
		penalty+=totalPenalty;
		for(int i=0;i<(tree[node].child).size();i++)
				stackTree.push_back(tree[node].child[i]);
	}
	cout<<penalty;
    return 0;
}
