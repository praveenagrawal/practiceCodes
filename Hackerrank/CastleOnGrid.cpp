#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct cellG
{
    int i;
    int j;
    int status;
};

int changeStatus(vector<vector<int>> &A, int i, int j, vector<cellG> &Q, int prevStatus)
{
    int result = 1;
    if(A[i][j]==-1)
    {
        cellG temp;
        temp.i = i;
        temp.j = j;
        temp.status = prevStatus+1;
        A[i][j]=prevStatus+1;
        Q.push_back(temp);
    }
    else if(A[i][j]==-3)
        result = 2; //Done
    else
        result = 3;  //Break   
    return result;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;
    std::vector<vector <int>> A(N);
    string s;
    for(int i=0;i<N;i++)
    {
        cin>>s;
        for(int j = 0;j<N;j++)
        {
            if(s[j]=='.')
                A[i].push_back(-1);  //BLANK
            else
                A[i].push_back(-10);    //OBSTACLES
        }
    }
    std::vector<cellG> Q;
    cellG start, dest;
    cin>>start.i;
    cin>>start.j;
    cin>>dest.i;
    cin>>dest.j;
    start.status = 0;  //START
    dest.status = -3;   //DESTINATION
    A[start.i][start.j] = 0; A[dest.i][dest.j]=-3;
    Q.push_back(start);
    int count = 1;
    int result = 1;
    while(result!=2)
    {
        cellG current = Q.front();
        Q.erase(Q.begin());
        for(int i=current.i+1; i<N && result!=2;i++)
        {
            result=changeStatus(A, i, current.j, Q, current.status);
            if(result!=1)
                break;
        }
        for(int i=current.i-1; i>=0 && result!=2;i--)
        {
            result=changeStatus(A, i, current.j, Q, current.status);
            if(result!=1)
                break;
        }
        for(int j=current.j+1;j<N && result!=2;j++)
        {
            result=changeStatus(A, current.i, j, Q, current.status);
            if(result!=1)
                break;
        }
        for(int j=current.j-1;j>=0 && result!=2;j--)
        {
            result=changeStatus(A, current.i, j, Q, current.status);
            if(result!=1)
                break;
        }
        if(result==2)
        {
            cout<<current.status+1;
        }
    }

    return 0;
}