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

struct band
{
    int A;
    int B;
    int P;
};

bool compare(band l, band r)
{
  return l.P<r.P;
}

inline void solve()
{
	int n,m,l;
  cin>>n>>m>>l;
  std::vector<band> bands(n);
  for(int i=0;i<n;i++)
  {
    band thisBand;
    cin>>thisBand.A;
    cin>>thisBand.B;
    cin>>thisBand.P;  
    bands[i] = thisBand;
  }
  std::vector<ull> price(l, ULLONG_MAX);
  sort(bands.begin(), bands.end(), compare);
  for(int i=0;i<l;i++)
  {
    ull minCost = ULLONG_MAX;
    for(int j=0;j<n;j++)
    {
      if(bands[j].A>=i+1 && bands[j].B<=i+1 && minCost>bands[j].P && bands[j].P<=m)
        minCost = bands[j].P;
    }
    for(int j=0;j<l-1;j++)
    {
      int k = i-1-j;
      if(k<0)
        break;
      if(k>=0 && price[j]+price[k]<minCost && price[j]+price[k]<=m)
        minCost = price[j]+price[k];
    }
    price[i]=minCost;
  }
  if(price[l-1]==ULLONG_MAX)
    cout<<"IMPOSSIBLE\n";
  else
    cout<<price[l-1]<<endl;
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