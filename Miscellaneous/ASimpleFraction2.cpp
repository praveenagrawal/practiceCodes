#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

string findDecimal(int n, int d)
{
	unordered_map <int, int> mapA;
	mapA.clear();
	int rem = n%d;
	if(rem==0)
		return to_string(n/d);
	string result = "";
	while(rem!=0 && mapA.find(rem)==mapA.end())
	{
		mapA[rem] = result.length();
		rem*=10;
		result+= to_string(rem/d);
		rem = rem%d;
	}
	if(rem==0)
		result = to_string(n/d) + '.' + result;
	else
		result = to_string(n/d) + '.' + result.substr(0,mapA[rem]) + '(' + result.substr(mapA[rem],result.size()-mapA[rem]) + ')';
	return result;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		cout<<findDecimal(n,d)<<endl;
	}
}