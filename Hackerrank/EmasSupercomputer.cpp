#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int i;
	int j;
};

struct cross
{
	int area;
	std::vector<node> cells;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++)
    	cin>>grid[i];
    vector<cross> stackCross;
    for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cross thisCross;
			int t=0;
			if(grid[i][j]=='G')
			{
				thisCross.area = 1;
				node thisNode;
				thisNode.i = i;
				thisNode.j = j;
				(thisCross.cells).push_back(thisNode);
				stackCross.push_back(thisCross);
				if(i!=0 && i!=n-1 && j!=0 && j!=m-1)
				{
					int k=1;
					while(i+k<n && i-k>=0 && j+k<m && j-k>=0)
					{
						if(grid[i-k][j]=='G' && grid[i+k][j]=='G' && grid[i][j+k]=='G' && grid[i][j-k]=='G')
						{
							thisCross.area = 4*k + 1;
							node node1,node2,node3,node4;
							node1.i = i-k; node1.j = j;
							node2.i = i+k; node2.j = j;
							node3.i = i;   node3.j = j+k;
							node4.i = i;   node4.j = j-k;
							thisCross.cells.push_back(node1);
							thisCross.cells.push_back(node2);
							thisCross.cells.push_back(node3);
							thisCross.cells.push_back(node4);
							stackCross.push_back(thisCross);
							k++;
						}
						else
							break;
					}
				}
			}
		}
	}
	int maxProduct = 0;
	for(int i=0;i<stackCross.size()-1;i++)
	{
		for(int j=i+1;j<stackCross.size();j++)
		{
			bool overlap = false;
			for(int k=0;k<stackCross[i].cells.size() && overlap==false;k++)
			{
				for(int l=0;l<stackCross[j].cells.size() && overlap ==false;l++)
				{
					if(stackCross[i].cells[k].i==stackCross[j].cells[l].i && stackCross[i].cells[k].j==stackCross[j].cells[l].j)
						overlap=true;
				}
			}
			if(!overlap && stackCross[i].area*stackCross[j].area>maxProduct)
				maxProduct = stackCross[i].area*stackCross[j].area;
		}
	}
	cout<<maxProduct;
    return 0;
}
