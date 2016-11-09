#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int T;
	cin>>T;
	string M;
	cin>>M;
	while(T--)
	{
		string S;
		cin>>S;
		string result = "";
		for(int i=0;i<S.length();i++)
		{
			if(S[i]=='_')
				result+=" ";
			else if(S[i]=='.' ||S[i]==',' || S[i]=='!' || S[i]=='?')
				result+=S[i];
			else
			{
				int temp = S[i];
				if(temp>=65 && temp<=90)
				{
					temp-=65;
					temp = M[temp];
					temp-=32;
					result+=temp;
				}
				else if(temp>=97 && temp<=122)
				{
					temp-=97;
					temp = M[temp];
					result+=temp;
				}
			}
		}
		cout<<result<<endl;
	}
}