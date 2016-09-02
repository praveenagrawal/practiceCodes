/*
Node is defined as 
*/
#include <iostream>
typedef struct node
{
   int data;
   node * left;
   node * right;
}node;


/*
void insertNode(node *root, node *newNode)
{
    if(root==NULL)
        root=newNode;
    else if(root->data>=newNode->data)
        insertNode(root->left, newNode);
    else
        insertNode(root->right, newNode);
}
*/
using namespace std;
node * insert(node * root, int value)
{
    
    if(root==NULL)
    {
            node *newNode = new node();
        newNode->data = value;
        newNode->left = NULL; newNode->right = NULL;
        root = newNode;
        //root->data = value;
        //root->left = NULL;
        //root->right = NULL;
    }
    else
    {
        if(root->data>value)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);
    }
   return root;
}
int main()
{
    int N;
    cin>>N;
    node *root = new node();
    root->left= NULL; root->right = NULL;
    while(N--)
    {
        int t;
        cin>>t;
        insert(root, t);
        cout<<root->data<<"    jksfksjfs\n";
        cout<<root->left->data<<"    jksfksjfs\n";
        cout<<root->right->data<<"    jksfksjfs\n";  
    }
}