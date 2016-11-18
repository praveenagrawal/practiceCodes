#include <iostream>
#include <vector>
using namespace std;

typedef std::vector<int> vi;

void propagateCarry(vi &A, int i, int j)
{
	int carry=1;
	if(i==j)
	{
		if(A[i]==9)
		{
			A[i] = 0;
			carry = 1;
		}
		else
		{
			A[i]++;
			carry = 0;
		}
		i--;
		j++;
	}
	while(carry!=0)
	{
		if(A[i]==9)
		{
			A[i] = 0;
			A[j] = 0;
			carry = 1;
		}
		else
		{
			A[i]++;
			A[j]++;
			carry = 0;
		}
		i--;
		j++;
	}
}

void nextPalindrome(vi &A)
{
	int n = A.size();
	bool all9 = 1;
	for(int i=0;i<n;i++)
	{
		if(A[i]!=9)
		{
			all9 = 0;
			break;
		}
	}
	if(all9)
	{
		A[0] = 1;
		for(int i=1; i<n;i++)
			A[i] = 0;
		A.push_back(1);
	}
	else
	{
		int i,j;
		if(n%2==0)
		{
			i = n/2 - 1;
			j = i + 1;
		}
		else
		{
			i = n/2 - 1;
			j = n/2 + 1;
		}
		while(A[i]==A[j] && i>=0)
		{
			i--;
			j++;
		}
		if(i<0)
		{
			i = n/2 - 1; j = i + 1;
			if(n%2==1)
			{
				i = n/2;
				j = n/2;
			}
			propagateCarry(A, i, j);
		}
		else
		{
			bool reflectionSufficient = false;
			if(A[i]>A[j])
				reflectionSufficient = 1;
			while(i>=0)
			{
				A[j] = A[i];
				i--;
				j++;
			}
			if(!reflectionSufficient)
			{
				if(n%2==0)
				{
					i = n/2 - 1;
					j = i + 1;
				}
				else
				{
					i = n/2;
					j = n/2;
				}
				propagateCarry(A, i, j);
			}
		}
	}
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vi A;
		for(int i=0;i<n;i++)
		{
			int t;
			cin>>t;
			A.push_back(t);
		}
		nextPalindrome(A);
		n = A.size();
		for(int i=0;i<n;i++)
			cout<<A[i]<<" ";
		cout<<endl;
	}
	return 0;
}