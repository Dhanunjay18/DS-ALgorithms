#include "iostream"
using namespace std;

struct Node 
{
    int data;
    Node *right,*left;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node *insert(Node *root, int key){
    Node *n = new Node(key);
    if(root==NULL)
        return n;
    if(key<root->data)
        root->left = insert(root->left,key);
    else
        root->right = insert(root->right, key);
    return root;        
}

bool search(Node *root, int key){
    if(root==NULL)
        return false;
    if(key==root->data)
        return true;
    if(key<root->data)
        return search(root->left,key);
    else    
        return search(root->right,key);
}

int findMin(Node *root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root->data;
}

void display(Node *root){
    if(root==NULL)
        return;
    display(root->left);    
    display(root->right);
    cout<<root->data<<" ";
}

void preorder(Node *root){
    if(root==NULL)
        return ;
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right); 
}
int main(){
    Node *root = NULL;
    root = insert(root,30);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,10);   
    root = insert(root,50);
    root = insert(root,5);
    display(root);
    cout<<endl;    
    int t;
    cout<<"Enter teh elemetns to find mininmum : "<<endl;
    cin>>t;
    if(search(root,t))
        cout<<"Found"<<endl;
    else    cout<<"NOT FOUND"<<endl;
    cout<<"Minimum is : "<<findMin(root)<<endl;
    return 0;
}