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

int count( std::vector<ll> S, int n)
{
    int m = 3;
    vector <ll> table(n+1,0);
    table[0] = 1;
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];
 
    return table[n];
}

inline void solve()
{
	ll n,d;
  cin>>n>>d;
  ll result = 0;
  for(int i=d;i<=n;i+=d)
  {
    std::vector<ll> S(3);
    S[0] = i, S[1] = i+1, S[2] = i+2;
    result+=count(S, n-i);
  }
  
  cout<<result<<endl;
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