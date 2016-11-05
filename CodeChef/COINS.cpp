#include <iostream>
#include <vector>
using namespace std;
vector <int> list(100000,0);
unsigned long int temp;
unsigned long int exchange(unsigned long int n)
{
	temp = 0;
	if(n<12)
	{
		list[n] = n;
		return n;
	}
	else if(n>=0 && n<100000)
	{
		if(list[n]!=0)
			temp = list[n];
		else
			temp =  exchange(n/2)+ exchange(n/3) + exchange(n/4);
	}
	else
	{
		temp = exchange(n/2)+ exchange(n/3) + exchange(n/4);
		if(temp>n)
			return temp;
		else
			return n;
	}
	if(n < temp)
	{
		list[n] = temp;
		return temp;
	}
	else 
	{
		list[n] = n;
		return n;
	}

}
int main()
{
	unsigned long int n;
	while(cin>>n)
	{
		cout<<exchange(n)<<endl;
	}
}