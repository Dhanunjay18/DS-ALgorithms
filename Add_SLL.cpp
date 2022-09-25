#include<iostream>
using namespace std;
struct Node{
    int data;
    Node * next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insert(Node* &head,int val){
    Node* n = new Node(val) ;
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

void reverse(Node * &head){
    Node *prev,*curr,*next;
    prev = next = NULL;
    curr = head;
    while(curr!=NULL){
        next = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void display(Node *head){
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

void add_sll(Node* l1,Node* l2){
    Node *head = NULL;
    int c = 0;
    while(l1!=NULL || l2!=NULL){
        int x = l1->data + l2->data + c;
        int y = x % 10;
        c = x/10;
        insert(head,y);
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    cout<<"Sum of above two Linked Lists is : "<<endl;
    reverse(head);
    display(head);
}

int main(){
    Node *head1 = NULL, *head2=NULL;
    insert(head1,1);
    insert(head1,2);
    insert(head1,3);
    insert(head1,4);
    insert(head2,5);
    insert(head2,6);
    insert(head2,7);
    insert(head2,8);
    display(head1);
    display(head2);
    reverse(head1);
    reverse(head2);
    add_sll(head1,head2);
    return 0;
}