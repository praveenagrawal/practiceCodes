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

struct node{
 int val;
 int up;
 int left;
 int down;
 int right;
 node()
 {
  val = up = left = 0;
 }

 void print(int i,int j)
 {
  cout<<i<<","<<j<<": "<<val<<" - u "<<up<<" - l "<<left<<endl;
 }
};

int fill1(int r,int c)
{
  vector<vector<node> > grid(r,vector<node>(c));
  int count = 0;
  for (int i = 0; i < r; ++i)
  {
    for (int j = 0; j < c; ++j)
    {
      if(j==0 || grid[i][j-1].left == 0)
      {
        if(i==0 || grid[i-1][j].up == 0)
        {
          count++;
          grid[i][j].val = 1;
          if(!(j==0 || grid[i][j-1].val == 0))
          {
            grid[i][j].left = 1;
          }
          if(!(i==0 || grid[i-1][j].val == 0))
          {
            grid[i][j].up  = 1;
          }
        }
      }
    }
  }
  return count;
}
int fill(int r,int c,int type)
{
  //cout<<"*****\n";
  vector<vector<node> > grid(r,vector<node>(c));
  int n = r+c-1;
  grid[0][0].val = type;
  //grid[0][0].print(0,0);
  int count = type;

  type = (type+1)%3;
  for (int k = 1; k < n; ++k)
  {
    int j = min(k,c-1),i;
    i = k - j;
    while(j>=0 && i>=0 && i < r && j < c)
    {
      /*if(j==0 || grid[i][j-1].left == 0)
      {
        if(i==0 || grid[i-1][j].up == 0)
        {
          count++;
          grid[i][j].val = 1;
          if(!(j==0 || grid[i][j-1].val == 0))
          {
            grid[i][j].left = 1;
          }
          if(!(i==0 || grid[i-1][j].val == 0))
          {
            grid[i][j].up  = 1;
          }
        }
      
      }*/
      grid[i][j].val  = type;
      count+= (type>0 ? 1 : 0);
      //grid[i][j].print(i,j);
      j--;
      i = k-j;
    }
    type = (type+1)%3;
  }
  return count;
}

inline void solve()
{
	int r,c;
  cin>>r>>c;
  cout<<max(max(fill(r,c,0) , fill(r,c,1)),fill1(r,c))<<endl;
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