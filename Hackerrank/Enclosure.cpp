#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define PI 3.14159265

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    std::vector<int> L(n);
    int Lmax = 0;
    for(int i=0;i<n;i++)
	{
		cin>>L[i];
		if(L[i]>Lmax)
			Lmax = L[i];
	}
	float Rn = 0, Rn1=Lmax;
	while(abs(Rn-Rn1)>0.0001)
	{
		Rn=Rn1;
		float numerator = 0, denominator = 0;
		for(int i=0;i<n;i++)
		{
			numerator+= asin(L[i]/(2*Rn));
			denominator+= L[i]/(sqrt(4*Rn*Rn-L[i]*L[i]));
		}
		denominator/=Rn;
		numerator-= PI;
		cout<<numerator<< "                 "<<denominator<<endl;
		Rn1 = Rn -(numerator/denominator);
		cout<<Rn1<<endl;
	}
	cout<<Rn1<<"  rfkr";
	/*float Rn_1 = 1.01*Lmax, Rn = Lmax, Rn1 = Lmax, fn_1=0;
	for(int i=0;i<n;i++)
		fn_1+= asin(L[i]/(2*Rn_1));
	while(abs(Rn1-Rn_1)>0.0001)
	{
		float numerator = 0, denominator = 0, fn = 0;
		for(int i=0;i<n;i++)
			fn+= asin(L[i]/(2*Rn));
		denominator = (fn-fn_1)/(Rn-Rn_1);
		cout<<fn<< "                 "<<denominator<<endl;
		Rn1 = Rn - fn/denominator;
		cout<<Rn1<<endl;
		fn_1 = fn;
		Rn_1 = Rn;
		Rn=Rn1;
	}*/

    return 0;
}
