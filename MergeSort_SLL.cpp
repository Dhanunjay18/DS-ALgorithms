#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
void split(Node *head,Node *&head1, Node *&head2){
    Node *fast,*slow;
    slow = head;
    fast = head -> next;
    while(fast!=NULL){
        fast = fast -> next;
        if(fast!=NULL){
            fast = fast -> next;
            slow = slow -> next;
        }
    }
    head1 = head;
    head2 = slow -> next;
    slow -> next = NULL;
}
Node *merge(Node *head1, Node *head2){
    if(head1==NULL)  return head2;
    if(head2==NULL)  return head1;
    Node *res = NULL;
    if(head1->data <= head2->data){
        res = head1;
        res -> next = merge(head1->next, head2);
    }
    else{
        res = head2;
        res -> next = merge(head1, head2->next);
    }
    return res;
}

void mergeSort(Node *&head){
    Node *temp = head;
    Node *a, *b;
    // Return from the function if there are only atmost 1 element
    if(temp == NULL || temp -> next == NULL)
        return;
    split(temp,a,b);
    mergeSort(a); mergeSort(b);
    head = merge(a,b);
}

void insert(Node *&head, int val){
    Node *n = new Node(val);
    if(head==NULL){
        head = n;
        return;
    }
    
    Node *temp = head;
    while(temp->next!=NULL)
        temp = temp -> next;
    temp -> next = n;
}

void display(Node *head){
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head = head -> next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    int n;
    cout<<"Enter Values : "<<endl;
    cin>>n;
    Node *head = NULL;
    while(n--){
        int t;
        cin>>t;
        insert(head,t);
    }
    display(head);
    mergeSort(head);
    display(head);
    return 0;
}





















