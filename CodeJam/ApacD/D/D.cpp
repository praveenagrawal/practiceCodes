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

//bool nonOverlap(int j, int k, int n, int l, std::vector<band> &bands, std::vector<ull> &price, std::vector<std::vector<int> > indexes)

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
  ull powSize = pow(2,n);
  int counter,j;
  ull minCost = ULLONG_MAX;
  for(counter = 0; counter < powSize; counter++)
  {
    std::vector<int> subset;
    for(j = 0; j < n; j++)
    {
      if(counter & (1<<j))
      {
        subset.push_back(j);
      }
    }
    ull tempCost=0;
    int tempA=0, tempB=0;
    for(int i=0;i<subset.size();i++)
    {
      tempA+= bands[subset[i]].A;
      tempB+=bands[subset[i]].B;
      tempCost+=bands[subset[i]].P;
    }
    if(tempA<=l && tempB>=l && tempCost<=m && tempCost<minCost)
      minCost = tempCost;
    subset.clear();
  }
  if(minCost==ULLONG_MAX)
    cout<<"IMPOSSIBLE\n";
  else
    cout<<minCost<<endl;
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