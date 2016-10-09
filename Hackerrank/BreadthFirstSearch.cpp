#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	std::vector<int> adj;
	bool marked = 0;
	int d = -1;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin>>q;
    while(q--)
	{
		int n,m;
		cin>>n>>m;
		std::vector<node> graph(n);
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			u--; v--;
			graph[u].adj.push_back(v);
			graph[v].adj.push_back(u);
		}
		int s;
		cin>>s;
		s--;
		std::vector<int> Q;
		Q.push_back(s);
		graph[s].marked = 1;
		graph[s].d = 0;
		while(Q.size()!=0)
		{
			int v = Q[0];
			Q.erase(Q.begin());
			for(int j=0;j<graph[v].adj.size();j++)
			{
				int u = graph[v].adj[j];
				if(!graph[u].marked)
				{
					graph[u].marked = 1;
					graph[u].d = graph[v].d + 6;
					Q.push_back(u);
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			if(i!=s)
				cout<<graph[i].d<<" ";
		}
		cout<<endl;
	}
    return 0;
}
