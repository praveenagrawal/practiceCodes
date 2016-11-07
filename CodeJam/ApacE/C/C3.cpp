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

int fn(int n,int mi,int ma) {  
 //cout<<n<<" , "<<mi<<" , "<<ma<<endl;
  if(n<mi)
    return 0;

  int ans = 0;
  for (int i = mi; i <= ma; ++i)
  {
    if(n == i)
      ans++;
    else
      ans += fn(n-i,max(mi,i),ma); 
  }
  return ans;
}

inline void solve()
{
	ll n,d;
  cin>>n>>d;
  
  int ans  = 0;
  for (int i = d; i <= n ; i+=d)
  {

    if(i<n)
    ans+=fn(n-i,i,i+2);

    else ans++;

    //cout<<i<<" : "<<fn(n-i,i,i+2)<<endl;
  }
  cout<<ans<<endl;
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