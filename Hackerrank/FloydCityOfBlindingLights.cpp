#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vi> vii;
#define INF 9999999

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n,m;
	cin>>n>>m;
	vii graph(n, vi(n, INF));
	for(int i=0;i<n;i++)
		graph[i][i] = 0;
	for(int i=0;i<m;i++)
	{
		int x,y,r;
		cin>>x>>y>>r;
		x--; y--;
		graph[x][y] = r;
	}
	for (int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(graph[i][j]>graph[i][k]+graph[k][j])
					graph[i][j]=graph[i][k]+graph[k][j];
			}
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		int a, b;
		cin>>a>>b;
		a--; b--;
		if(graph[a][b]==INF)
			cout<<-1<<endl;
		else
			cout<<graph[a][b]<<endl;
	}
    return 0;
}
