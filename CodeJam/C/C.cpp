#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair <int, int> pii;
typedef pair<string,string> pss;
typedef pair<ll,ll> pll;

ld PI = acos(-1);
#define MOD  1000000007


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

int IsEqual(string s1,string s2)
{
  vector<int> v1(26,0) , v2(26,0);
  int l = s1.size();
  for (int i = 0; i < l; ++i)
  {
    v1[s1[i] - 'a'] ++;
  } 
  l = s2.size();
  for (int i = 0; i < l; ++i)
  {
    v2[s2[i] - 'a'] ++;
  } 

  for (int i = 0; i < 26; ++i)
  {
    if(v1[i] != v2[i])
      return 0;
  }
  return 1;
}

int solveR(vector<string> &vocab,string s)
{
  if(s.size() == 0)
    return 1;
  int l;
  int chk;
  long long result = 0,tmp;
  for (int i = 0; i < vocab.size(); ++i)
  {
    l = vocab[i].size();
    if(IsEqual(vocab[i] , s.substr(0,l)))
    {
      result += solveR(vocab,s.substr(l));
      if(result > MOD)
        result = result % MOD;
    }
  }
  return result;
}

inline void solve()
{
	 int v,s;
   cin>>v>>s;
   std::vector<string> vocab(v);
   std::vector<string> sentences(s);
   for(int i=0;i<v;i++)
      cin>>vocab[i];

  sort(vocab.begin(), vocab.end());

  for(int i=0;i<s;i++)
  {
      cin>>sentences[i];
      cout<<solveR(vocab,sentences[i])<<" ";
  }
  cout<<endl;
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