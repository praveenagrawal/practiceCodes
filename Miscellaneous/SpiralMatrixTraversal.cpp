#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		std::vector<std::vector<int> > A(4, std::vector<int> (4));
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
				cin>>A[i][j];
		}
		cout<<A[0][0]<<" ";
		int i=0, j=1,l=3;
		int direction = 1;	// 1-> right , 2-> down, 3-> left, 4->up
		for(int count=1;count<16;count++)
		{
			cout<<A[i][j]<<" ";
			if(direction==1)
			{
				if(j<l)
					j++;
				else if(j==l)
				{
					direction = 2;
					i++;
				}
			}
			else if(direction==2)
			{
				if(i<l)
					i++;
				else if(i==l)
				{
					direction = 3;
					j--;
				}
			}
			else if(direction==3)
			{
				if(j>3-l)
					j--;
				else if(j==3-l)
				{
					direction = 4;
					i--;
					l--;
				}
			}
			else
			{
				if(i>3-l)
					i--;
				else
				{
					direction = 1;
					j++;
				}
			}
		}
		cout<<endl;
	}
}