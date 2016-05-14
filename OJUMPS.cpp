#include <iostream>
using namespace std;
int main()
{
	unsigned long long a;
	cin>>a;
	a = a%6;
	if(a==0 || a==1 || a==3)
		cout<<"yes\n";
	else
		cout<<"no\n";

}