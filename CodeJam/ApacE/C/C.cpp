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
	int n,d;
  cin>>n>>d;
  ull result=0;
  std::vector<int> p(n);
  int k=0;
  p[k] = n;  // Initialize first partition as number itself
  while (true)
  {
    cout<<k<<endl;
    if(p[k]%d==0 && p[0]-p[k]<=2)
      result++;
    int rem_val = 0;
    while (k >= 0 && p[k] == 1)
    {
        rem_val += p[k];
        k--;
    }
    if (k < 0)  break;
    p[k]--;
    rem_val++;
    while (rem_val > p[k])
    {
      p[k+1] = p[k];
      rem_val = rem_val - p[k];
      k++;
    }
    p[k+1] = rem_val;
    k++;
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