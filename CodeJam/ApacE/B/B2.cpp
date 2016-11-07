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

int ifOneInBaseN(ll num , ll &base)
{
  while(num > 0)
  {
    //cout<<num<<" "<<base<<" "<<num % base<<endl;
    if(num % base != 1){

      return 0;
    }
    num = num/base;
  }
  return 1;
}

inline void solve()
{
	ll n,i;
  cin>>n;
  ll lastAns = -1;
  for (i = 2; i < cbrt(n); ++i)
  {
    if(ifOneInBaseN(n,i)==1)
    {
      cout<<i<<endl;
      return;
    }
  }

  for(i = sqrt(n); (i + i*i + 1) >= n ; --i)
  {
    if(ifOneInBaseN(n,i)==1)
    {
      cout<<i<<endl;
      return;
    }
  }


  cout<<n-1<<endl;
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