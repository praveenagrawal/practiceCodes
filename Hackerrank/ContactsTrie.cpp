#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int SIZE = 26;

struct node
{
    struct node *children[26];
    bool isLeaf = 0;
    int leaves = 0;
};

void addName(node* &root, string name)
{
    int n = name.size();
    node *temp = root;
    for(int i=0;i<n;i++)
    {
        if(temp->children[name[i]-'a']==NULL)
        {
            node *newNode = new node();
            temp->children[name[i]-'a'] = newNode;
        }
        temp = temp->children[name[i]-'a'];
        temp->leaves++;
    }
    temp->isLeaf = 1;
}

int findPartial(node* &root, string partial)
{
    if(root==NULL)
        return 0;
    int n = partial.size();
    node *temp = root;
    for(int i=0;i<n;i++)
    {
        if(temp->children[partial[i]-'a']==NULL)
            return 0;
        temp = temp->children[partial[i]-'a'];
    }
    return temp->leaves;
}

int main() 
{
    int n;
    cin>>n;
    node *root = new node();
    while(n--)
    {
        string op;
        cin>>op;
        if(op=="add")
        {
            string name;
            cin>>name;
            addName(root, name);
        }
        else if(op=="find")
        {
            string partial;
            cin>>partial;
            cout<<findPartial(root, partial)<<endl;
        }
    }
    return 0;
}
