#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

bool findSubarray(std::vector<int> &A, int s)
{
	int n = A.size();
	map <int, int> mapA;
	int currentSum = 0;
	for(int i=0;i<n;i++)
	{
		currentSum+= A[i];
		if(currentSum==s)
		{
			cout<<1<<" "<<i+1<<endl;
			return 1;
		}
		if(mapA.find(currentSum-s)!=mapA.end())
		{
			cout<<mapA[currentSum-s]+2<<" "<<i+1<<endl;
			return 1;
		}
		mapA[currentSum] = i;
	}
	return 0;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,s;
		cin>>n>>s;
		std::vector<int> A(n);
		for(int i=0;i<n;i++)
			cin>>A[i];
		if(!findSubarray(A, s))
			cout<<-1<<endl;

	}
}