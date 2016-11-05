#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int min = 0,max = 0;
	vector<float> area(N,0);
	for(int iter=0;iter<N;iter++)
	{
		int x1, x2,x3,y1,y2,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		area[iter] = fabs(x2*y3 - x3*y2 + x3*y1 - x1*y3 + x1*y2 - x2*y1);
		if(area[iter]>=area[max])
			max = iter;
		if(area[iter]<=area[min])
			min = iter;
	}
	cout<<min+1<<" "<<max+1<<endl;
}