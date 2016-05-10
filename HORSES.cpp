/*Chef is very fond of horses. He enjoys watching them race. As expected, he has a stable full of horses. He, along with his friends, goes to his stable during the weekends to watch a few of these horses race. Chef wants his friends to enjoy the race and so he wants the race to be close. This can happen only if the horses are comparable on their skill i.e. the difference in their skills is less.
There are N horses in the stable. The skill of the horse i is represented by an integer S[i]. The Chef needs to pick 2 horses for the race such that the difference in their skills is minimum. This way, he would be able to host a very interesting race. Your task is to help him do this and report the minimum difference that is possible between 2 horses in the race.
Input:

First line of the input file contains a single integer T, the number of test cases.
Every test case starts with a line containing the integer N.
The next line contains N space separated integers where the i-th integer is S[i].
Output:

For each test case, output a single line containing the minimum difference that is possible.
Constraints:

1 ≤ T ≤ 10
2 ≤ N ≤ 5000
1 ≤ S[i] ≤ 1000000000

Example:

Input:
1
5
4 9 1 32 13

Output:
3
*/
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int T,N; //Number of testcases
	int temp;
	
	cin>>T;
	for(int iter = 0; iter<T; iter++)
	{
		cin>>N;
		vector<int> S(N);
		for(int i=0;i<N;i++)
			cin>>S[i];
		for(int i=0;i<N;i++)
		{
			int min = i;
			for(int j=i+1;j<N;j++)
			{
				if(S[j]<S[min])
					min = j;
			}
			temp = S[i];
			S[i] = S[min];
			S[min] = temp;
		}
		int diff = S[1]-S[0];
		for(int i=0;i<N-1;i++)
		{
			if(diff>S[i+1]-S[i])
				diff = S[i+1]-S[i];
		}
		cout<<diff<<endl;
	}
	
}
