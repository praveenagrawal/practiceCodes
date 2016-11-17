#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::vector<int> vi;

int lzzs(vi &A)
{
	int n = A.size();
	vi dpI(n,1), dpD(n,1);
	int res = 0;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(A[j]<A[i])
				dpI[i] = max(dpI[i], dpD[j]+1);
			if(A[j]>A[i])
				dpD[i] = max(dpD[i], dpI[j]+1);
		}
		if(res<max(dpD[i], dpI[i]))
			res = max(dpD[i], dpI[i]);
	}
	return res;
}

int main()
{
	int n;
	cin>>n;
	vi A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	cout<<lzzs(A)<<endl;
}