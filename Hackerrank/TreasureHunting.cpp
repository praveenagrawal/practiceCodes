#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long double x1,y1,a,b,x,y,x2,y2,a1,b1,k;
    cin>>x1>>y1;
    cin>>a>>b;
    x = (a*b*y1 + a*a*x1)/(b*b + a*a);
    y = (b*b*y1 + a*b*x1)/(b*b + a*a);
    if(k!=0)
    	k = x/a;
    else
    	k=y/b;
    cout<<fixed<<setprecision(12)<<k<<endl;
    a1 = -b;
    b1 = a;
    if(a1!=0)
    	cout<<fixed<<setprecision(12)<<(x1-x)/a1;
    else
    	cout<<fixed<<setprecision(12)<<(y1-y)/b1;
    return 0;
}
