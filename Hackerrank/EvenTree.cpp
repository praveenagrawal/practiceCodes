#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back

struct node
{
	std::vector<int> adj;
	int children = 0;
};

int findChildren(std::vector<node> &tree, int root)
{
	if(tree[root].adj.size()==0)
	{
		tree[root].children = 1;
		return 1;
	}
	for(int i=0;i<tree[root].adj.size();i++)
		tree[root].children+= findChildren(tree, tree[root].adj[i]);
	tree[root].children++;
	return tree[root].children;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin>>n>>m;
    std::vector<node> tree(n);
    for(int i=0;i<m;i++)
   	{
   		int u,v;
   		cin>>u>>v;
   		u--; v--;
   		//tree[u].adj.pb(v);
   		tree[v].adj.pb(u);
   	}
   	findChildren(tree, 0);
   	int count = 0;
   	for(int i=1;i<n;i++)
	{
		if(tree[i].children%2==0 && tree[i].children!=0)
			count++;
	}
	cout<<count<<endl;
    return 0;
}
