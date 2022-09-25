#include<iostream>
using namespace std;

struct Node {
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

int rearrange(Node *head){
    Node *p1 , *p2;
    //1. Find the middle Element
    if(head!=NULL){
        p1 = p2 = head;
        while(p2 && p2->next){
            p1 = p1 -> next;
            p2 = p2 -> next -> next;            
        }
    }
    //2. Split as 2 Linked Lists as below and reverse second LL
    Node *head1 = head;
    Node *head2 = p1->next;
    p1->next = NULL;
    reverse(head2);
    //3. Create 3rd Linked list initially points to NULL
    Node *head3 = NULL;
    int flag = 1;
    //4. Insert Values to linked list while both becomes null 
    while(head1 || head2){
        if(head1!=NULL){
            insert(head3,head1->data);
            head1 = head1->next;
        }
        if(head2!=NULL)
        {
            insert(head3,head2->data);
            head2 = head2->next;
        }
    }
    //5. Display the result here itself
    display(head3);
}



int main(){
    Node *head=NULL;
    int n;
    cin>>n;
    cout<<"Enter values : "<<endl;
    while(n--)
    {
        int t;
        cin>>t;
        insert(head,t);
    }    
    // cout<<middleElement(head)<<endl;
    rearrange(head);

    return 0;
}