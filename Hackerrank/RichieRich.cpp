#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(string s)
{
	int n = s.size();
	for(int i=0, j=n-1;i<=j;i++, j--)
	{
		if(s[i]!=s[j])
			return 0;
	}
	return 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string s;
    int n,k;
    cin>>n>>k;
    cin>>s;
    std::vector<bool> A(n,0);
	int temp = n;
	int count = 0;
	int i=0, j=n-1;
	while(count<k && i<=j)
	{
		if(s[i]<s[j])
		{
			A[i] = 1;
			s[i] = s[j];
			count++;
		}
		else if(s[i]>s[j])
		{
			A[j] = 1;
			s[j] = s[i];
			count++;
		}
		i++; j--;
	}
	if(!isPalindrome(s))
	{
		cout<<-1<<endl;
		return 0;
	}
	for(i=0, j=n-1;i<=j && count <k; i++, j--)
	{
		if(s[i]!='9')
		{
			if(A[i]==0 && A[j]==0)
			{
				if(i==j)
				{
					A[i] = 1;
					count++;
					s[i] = '9';
				}
				else if(k-count>=2)
				{
					A[i] = 1; A[j] = 1;
					count+=2;
					s[i] = '9'; s[j] = '9';
				}
			}
			else if(A[i]==0)
			{
				s[i] = '9'; s[j] = '9';
				A[i] = 1;
				count++;
			}
			else if(A[j]==0)
			{
				s[i] = '9'; s[j] = '9';
				A[j] = 1;
				count++;
			}
		}
	}
	cout<<s;
    return 0;
}
