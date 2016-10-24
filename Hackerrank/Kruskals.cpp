#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair <int, int> pii; // <node, weight>
typedef unsigned long long ull;


struct node
{
	std::vector<pii> adj;
	int parent = -1;
};

struct edge
{
	int source;
	int dest;
	int w;
};

struct subset
{
	int parent;
	int rank;
};

bool myFunc(edge l, edge r)
{
	return l.w<r.w;
}

int find(std::vector<subset> &subsets, int i)
{
	if(subsets[i].parent!=i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}

void Union(std::vector<subset> &subsets, int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if(subsets[xroot].rank <subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if(subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin>>n>>m;
    std::vector<node> graph(n);
    std::vector<edge> edges(m);
    std::vector<subset> subsets(n);
    ull result = 0;
    for(int i=0;i<m;i++)
	{
		int x,y,r;
		cin>>x>>y>>r;
		x--; y--;
		graph[x].adj.push_back(make_pair(y, r));
		graph[y].adj.push_back(make_pair(x, r));
		edges[i].source = x; edges[i].dest = y; edges[i].w = r;
	}
	sort(edges.begin(), edges.end(), myFunc);
	for(int i=0;i<n;i++)
	{
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}
	int i=0,e=0;
	while(e<n-1)
	{
		edge thisEdge = edges[i++];
		int x = find(subsets, thisEdge.source);
		int y = find(subsets, thisEdge.dest);
		if(x!=y)
		{
			e++;
			result+=thisEdge.w;
			graph[x].parent = y;
			Union(subsets, x,y);
		}
	}
	cout<<result;
    return 0;
}
