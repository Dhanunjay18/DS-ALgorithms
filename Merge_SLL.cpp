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

/*
        There are only 3 Steps to Merge two Sorted Single Lists :
        1 -> If First SLL is NULL then return whole second SLL
        2 -> If Second SLL is NULL then return whole first SLL
        3 -> Else if both are not empty 
            --Compare both Linked Lists data and recursively call the merge function.
*/

Node *merge(Node *head1, Node *head2){
        if(head1==NULL)
            return head2;
        if(head2==NULL)
            return head1;
        Node *res = NULL;
        if(head1->data <= head2->data){
            res = head1;
            res -> next = merge(head1->next, head2);
        }
        else{
            res = head2;
            res->next = merge(head1, head2->next);
        }
        return res;
}



void insert(Node *&head, int data){
    Node *n = new Node(data);
    if(head==NULL){
        head = n;
        return;
    }
    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp -> next;
    }
    temp->next = n;
}


void display(Node *head){
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head = head -> next;
    }
    cout<<" NULL"<<endl;
}


int main(){         // ** Remember that this Function is to only merge for Sorted SLL
    int l1, l2;
    Node *head1, *head2;
    head1 = head2 = NULL;
    cout<<"List 1 : "<<endl;
    cin>>l1;
    for(int i=0;i<l1;i++){
        int t;
        cin>>t;
        insert(head1,t);
    }
    cout<<"List 2 : "<<endl;
    cin>>l2;
    for(int i=0;i<l2;i++){
        int t;
        cin>>t;
        insert(head2,t);
    }
    display(head1);
    display(head2);
    Node *mergeHead = merge(head1, head2);
    display(mergeHead);
    return 0;
}