#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

int gcd(int a, int b)
{
	if(a==0)
		return b;
	return gcd(b%a, a);
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		if(n%d==0)
		{
			cout<<n/d<<endl;
			continue;
		}
		int g = gcd(n,d);
		n/= g;
		d/= g;
		int temp = d;
		while(temp%2==0)
			temp/=2;
		bool rec = false;
		for(int i=3;temp!=0;i+=2)
		{
			if(temp%i==0)
			{
				temp/=i;
				if(i!=5)
				{
					rec = 1;
					break;
				}
			}
		}
		if(!rec)
			cout<<(fixed)<<setprecision(6)<<(double)n/d<<endl;
		else
		{
			string result = "";
			int q = n/d;
			do
			{
				int t = q%10;
				char ch = '0'+t;
				result= ch + result;
				q/=10;
			}while(q!=0);
			int r = n%d;
			if(q==0)
				r = n*10;
			//result+=".(";
			std::vector<int> rem(2001,-1);
			int i=0;
			string dec = "";
			while(1)
			{
				if(r<d)r*=10;
				while(r<d)
				{
					r*=10;
					dec+='0';
					i++;
				}
				q = r/d;
				if(rem[r]==-1)
				{
					char ch = '0'+q;
					dec+= ch;
					rem[r]=i;
					i++;
				}
				else
				{
					result+='.'+dec.substr(0,rem[r])+'('+dec.substr(rem[r],i-rem[r]+1)+')';
					break;
				}
				r = r%d;
			}
			cout<<result<<endl;
		}
	}
	return 0;
}