/*
    ||\\      ||
    || \\     ||
    ||  \\    ||
    ||   \\   ||
    ||    \\  ||
    ||     \\ ||  
    ||      \\||  
*/
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void insert(Node* &head,int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }
    Node * temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp -> next = n;
}


void display(Node *head){
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}



int main(){
    int l1,l2;    
    Node *head1, *head2;
    head1 = head2 = NULL;
    cout<<"List 1 : "<<endl;
    cin>>l1;
    for(int i=0;i<l1;i++)
    {
        int t;
        cin>>t;
        insert(head1,t);
    }

    cout<<"List 2 : "<<endl;
    cin>>l2;
    for(int i=0;i<l2;i++)
    {
        int t;
        cin>>t;
        insert(head2,t);
    }
    display(head1);
    display(head2);
    return 0;
}