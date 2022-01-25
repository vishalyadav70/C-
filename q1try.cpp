#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node (int val){
        data=val;
        next=NULL;
    }
};
void insertatHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
void insertionatTAil(node* &head,int val){
    
    node* n=new node(val);
    node* temp=head;
    if(head==NULL){
        insertatHead(head,val);
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;


}
node* evenafterodd(node* &head){
    node* odd=head;
    node* even=head->next;
    node* evenstart=even;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenstart;
    if(odd->next==NULL){
        even->next=NULL;
    }
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;

}
int main(){
    node* head=NULL;
    insertionatTAil(head,1);
    insertionatTAil(head,2);
    insertionatTAil(head,3);
    insertionatTAil(head,4);
    insertionatTAil(head,5);
    insertionatTAil(head,6);
    insertionatTAil(head,7);
    insertionatTAil(head,8);
    insertionatTAil(head,9);
    insertionatTAil(head,10);
    display(head);
    evenafterodd(head);
    display(head);
    return 0;
}