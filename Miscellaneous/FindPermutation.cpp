#include <iostream>
#include <vector>
using namespace std;

std::vector<int> findPerm(string s, int n)
{
	std::vector<int> result;
	std::vector<int> A;
	for(int i=1;i<=n;i++)
		A.push_back(i);
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='I')
		{
			result.push_back(A.front());
			A.erase(A.begin());
		}
		else
		{
			result.push_back(A.back());
			A.erase(A.end()-1);
		}
	}
	result.push_back(A.front());
	return result;
}


int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	std::vector<int> result;
	result = findPerm(s, n);
	for(int i=0;i<result.size();i++)
		cout<<result[i]<<" ";
}