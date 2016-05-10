/*
Input

There's no input.
Output

Output some form of these numbers: 137, 1315, 73, 136, 255, 1384, 16385, one per line in the listed order.
Example

Output:
The first two lines of the CORRECT output file are:

137=2(2(2)+2+2(0))+2(2+2(0))+2(0)
1315=2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)

The correct output file should contain 7 lines.
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

int main()
{
	int N[] = {137, 1315, 73, 136, 255, 1384, 16385};
	for(int i=0;i<7;i++)
	{
		string s="2";
		cout<<N[i]<<"=";
		vector <int> t;
		t.push_back(N[i]);
		while(t[0]!=0)
		{
			int k = 0;
			l:
			int j=0;
			while(1)
			{
				if(pow(2,j)>t[k])
				{
					j--;
					break;
				}
				j++;
			}
			if(j>2)
			{
				t.push_back(j);
				k++;
				t[k-1]-=pow(2,j);
				s+="(2";
				goto l;
			}
			else if(j == 2)
			{
				s+= "(2)";
				t[k]-=4;
				if(t[k]>0)
				{
					s+= "+2";
					goto l;
				}
				if(k>0)
				{
					t.pop_back();
					s+=')';
					k--;
				}
			}
			else if(j == 1)
			{
				t[k]-= 2;
				if(t[k]>0)
					s+="+2(0)";
				if(k>0)
				{
					t.pop_back();
					s+=')';
					k--;
				}
				else
					t[k] = 0;
			}
			else if(j == 0)
			{
				s+= "(0)";
				if(k>0)
				{
					t.pop_back();
					s+=')';
					k--;
				}	
				else
					t[k] = 0;
				
			}
			while(t[k]==0)
			{
				if(k==0)
					break;
				t.pop_back();
				k--;
				s+=')';
			}
			if(t[k]>0)
			{
				s+= "+2";
				goto l;
			}			
		}
		cout<<s<<endl;		

	}

}