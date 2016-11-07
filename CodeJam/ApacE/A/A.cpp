#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair <int, int> pii;
typedef pair<string,string> pss;
typedef pair<ll,ll> pll;

ld PI = acos(-1);
int MOD = 1000000007;


inline string IntToString(ll a)
{
  char x[100];
  sprintf(x,"%lld",a); string s = x;
  return s;
}

inline ll StringToInt(string a)
{
  char x[100]; ll res;
  strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
  return res;
}

inline string GetString(void)
{
  char x[1000005];
  scanf("%s",x); string s = x;
  return s;
}

inline string uppercase(string s){
  int n = s.size(); 
  for(int i=0;i<n;i++)
  	if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}

inline string lowercase(string s){
  int n = s.size();; 
  for(int i=0;i<n;i++)
  	if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}

inline void solve()
{
	string s;
  cin>>s;
  ull i1,i2;
  cin>>i1>>i2;
  ull n = s.size();
  ull countB = 0;
  for(ull i=0;i<n;i++)
  {
    if(s[i]=='B')
      countB++;
  }
  ull temp = i2%n, c2=0, c1=0;
  for(int i=0;i<temp;i++)
  {
    if(s[i]=='B')
      c2++;
  }
  temp = (i1-1)%n;
  for(int i=0;i<temp;i++)
  {
    if(s[i]=='B')
      c1++;
  }
  cout<<((i2/n)*countB) + c2 - (((i1-1)/n)*countB + c1)<<endl;
}


int main()
{
	int tests;
	cin>>tests;
	for(int i=1;i<=tests;i++)
	{
		cout<<"Case #"<<i<< ": ";
		solve();
	}
}	