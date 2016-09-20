#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;


node * insert(node * root, int value, std::vector<int> &numNodes, int d)
{
    
    if(root==NULL)
    {
        node *newNode = new node();
        newNode->data = value;
        newNode->left = NULL; newNode->right = NULL;
        root = newNode;
        numNodes[d]++;
    }
    else
    {
        if(root->data>value)
            root->left = insert(root->left, value, numNodes, d+1);
        else
            root->right = insert(root->right, value, numNodes, d+1);
    }
   return root;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    int a;
    cin>>n;
    node *root = new node();
    root = NULL;
    std::vector<int> numNodes(n);
    int d = 0;
    for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		root = insert(root, a, numNodes, d);
	}
	unsigned long long result = 0;
	for(int i=0;i<numNodes.size();i++)
		result+=numNodes[i]*i;
	cout<<result;

    return 0;
}
