#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string s;
		cin>>s;
		vector <int> count(26,0);
		int result = 0;
		for(int i=0;i<s.length();i++)
			count[s[i]-'a']++;
		for(int i=0;i<26;i++)
		{
			if(count[i]>0)
				result++;
		}
		cout<<result<<endl;
	}
}