#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
	{
		std::vector<float> x(4);
		std::vector<float> y(4);
		std::vector<float> z(4);
		for(int i=0;i<4;i++)
			cin>>x[i]>>y[i]>>z[i];
		float vec1x, vec1y,vec1z, vec2x, vec2y, vec2z;
		vec1x = x[1] - x[0];
		vec1y = y[1] - y[0];
		vec1z = z[1] - z[0];

		vec2x = x[2] - x[0];
		vec2y = y[2] - y[0];
		vec2z = z[2] - z[0];

		float cx, cy, cz;
		cx = vec1y*vec2z - vec1z*vec2y;
		cy = vec2x*vec1z - vec1x*vec2z;
		cz = vec1x*vec2y - vec1y*vec2x;

		if(cx*(x[3]-x[0])+cy*(y[3]-y[0])+cz*(z[3]-z[0])==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
    return 0;
}
