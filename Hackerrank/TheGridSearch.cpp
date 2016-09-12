#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int checkGrid(std::vector<string> &G, std::vector<string> &P, int i, int j, int r, int c)
{
    for(int Gi = i, Pi=0; Gi<i+r; Gi++, Pi++)
    {
        for(int Gj = j, Pj=0; Gj<j+c;Gj++, Pj++)
        {
            if(G[Gi][Gj]!=P[Pi][Pj])
                return 0;
        }
    }
    return 1;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        bool done = false;
        for(int i=0;i<R && !done ;i++)
        {
            for(int j=0;j<C && !done;j++)
            {
                if(G[i][j]==P[0][0] && i+r<=R && j+c<=C)
                {
                    if(checkGrid(G, P, i, j, r, c))
                        done = true;
                }
            }
        }
        if(done)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
