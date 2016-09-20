#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct point
{
	double x;	
	double y;
	double z;
};

struct triangle
{
	int a;
	int b;
	int c;
};

point findNormal(point v1, point v2)
{
	point normal;
	normal.x = v1.y*v2.z - v2.y*v1.z;
	normal.y = v2.x*v1.z - v1.x*v2.z;
	normal.z = v1.x*v2.y - v1.y*v2.x;
	double magnitude = sqrt(normal.x*normal.x + normal.y*normal.y + normal.z*normal.z);
	normal.x/= magnitude;
	normal.y/= magnitude;
	normal.z/= magnitude;
	return normal;
}

double findDistance(point Delta, triangle t, vector<point> &enemies)
{
	point p1,p2,p3;
	p1 = enemies[t.a];
	p2 = enemies[t.b];
	p3 = enemies[t.c];
	
	point v1,v2;
	v1.x = p1.x-p2.x;	v1.y = p1.y-p2.y; 	v1.z = p1.z-p2.z;
	v2.x = p3.x-p2.x; 	v2.y = p3.y-p2.y;	v2.z = p3.z-p2.z;
	point normal = findNormal(v1, v2);
	
	point vD;
	vD.x = Delta.x-p2.x;	vD.y = Delta.y-p2.y;	vD.z = Delta.z-p2.z;
	double distance = abs(vD.x*normal.x + vD.y*normal.y + vD.z*normal.z);
	return distance;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int m;
    cin>>m;
    point Delta;
    cin>>Delta.x>>Delta.y>>Delta.z;
    std::vector<triangle> tList(n);
    std::vector<point> enemies(m);
    for(int i=0;i<n;i++)
    	cin>>tList[i].a>>tList[i].b>>tList[i].c;
    for(int i=0;i<m;i++)
    	cin>>enemies[i].x>>enemies[i].y>>enemies[i].z;
    double minD;
    int minIndex = 0;
    minD = findDistance(Delta, tList[0], enemies);
    for(int i=1;i<n;i++)
	{
		double d;
		d = findDistance(Delta, tList[i], enemies);
		if(d<minD)
		{
			minD = d;
			minIndex = i;
		}
	}
	cout<<(fixed)<<setprecision(2)<<minD<<endl;
	cout<<minIndex;
    return 0;
}
