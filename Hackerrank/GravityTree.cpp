#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
	int vertex;
	Node *leftC = NULL;
	Node *rightS = NULL;
	Node *parent = NULL;
	bool status = false;//OFF
};

void resetTree(Node *node)
{
	node->status = false;
	Node *temp = node->rightS;
	while(temp!=NULL)
	{
		temp->status=false;
		temp = temp->rightS;
	}
	do
	{
		if(node->leftC!=NULL)
			resetTree(node->leftC);
		node=node->rightS;
	}while(node!=NULL);

}

void activateSubTreeV(Node *node)
{
	node->status = true;
	Node *temp = node->rightS;
	while(temp!=NULL)
	{
		temp->status = true;
		temp=temp->rightS;
	}
	do
	{
		if(node->leftC!=NULL)
			activateSubTreeV(node->leftC);
		node = node->rightS;
	}while(node!=NULL);
}

int findDistance(Node *U, Node *V)
{
	int d1 = 0;
	if(V==U)
		return d1;
	Node *temp = V->parent;
	std::vector<int> listPV;
	while(temp!=NULL)
	{
		listPV.push_back(temp->vertex);
		listPV.push_back(d1);
		d1++;
		if(temp==U)
			return d1;
		temp=temp->parent;
	}
	int n=listPV.size();
	Node *temp2 = U->parent;
	int d2 = 0;
	while(temp2!=NULL)
	{
		d2++;
		if(temp2==V)
			return d2;
		for(int i=0;i<n;i+=2)
		{
			if(temp2->vertex==listPV[i])
				return d2+listPV[i+1];
		}
		temp2 = temp2->parent;
	}
	return d1+d2;

}


void findForce(Node *U, Node *V, unsigned long long &force)
{
	int d = findDistance(U,V);
	force+=d*d;
	Node *temp = V->rightS;
	while(temp!=NULL)
	{
		force+=d*d;
		temp=temp->rightS;
	}
	do
	{
		if(V->leftC!=NULL)
			findForce(U, V->leftC, force);
		V = V->rightS;
	}while(V!=NULL);

}

Node * find(int v, Node *temp)
{
	if(temp->vertex==v)
		return temp;
	Node *temp1=temp->rightS;
	while(temp1!=NULL)
	{
		if(temp1->vertex==v)
			return temp1;
		temp1=temp1->rightS;
	}
	Node *temp2;
	do
	{
		if(temp->leftC!=NULL)
		{
			temp2=find(v,temp->leftC);
			if(temp2->vertex==v)
				return temp2;
		}
		temp=temp->rightS;
	}while(temp!=NULL);
	return NULL;
}

void insert(int v, Node *temp)
{
	Node *newNode = new Node();
	newNode->vertex = v;
	if(temp->leftC==NULL)
	{
		temp->leftC = newNode;
		newNode->parent = temp;
	}
	else 
	{
		temp=temp->leftC;
		while(temp->rightS!=NULL)
			temp=temp->rightS;
		temp->rightS=newNode;
		newNode->parent = temp->parent;
	}
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    Node *root = new Node();
    root->vertex = 1;
    Node *temp;
    temp = root;
    int vertexI = 2;
    for(int i=0;i<n-1;i++)
	{
		int v;
		cin>>v;
		temp = find(v,root);
		insert(vertexI, temp);
		vertexI++;
	}
	int q;
	cin>>q;
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		unsigned long long force = 0;
		resetTree(root);
		Node *nodeU;
		Node *nodeV;
		nodeV = find(v,root);
		nodeU = find(u,root);
		nodeV->status=true;
		if(nodeV->leftC!=NULL)
			activateSubTreeV(nodeV->leftC);
		int d = findDistance(nodeU, nodeV);
		force+=d*d;
		if(nodeV->leftC!=NULL)
			findForce(nodeU, nodeV->leftC, force);
		cout<<force<<endl;
	}


    return 0;
}
