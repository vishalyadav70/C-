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
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;

}
void insertatTAil(node* &head,int val){

    if(head==NULL){
        insertatHead(head,val);
        return;
    }
    node* n=new node(val);
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}
void deletefromhead(node* &head){
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    node* todel=temp->next;
    temp->next=head->next;
    head=head->next;
    delete todel;
}
void deletenode(node* &head,int pos){

    if(pos==1){
        deletefromhead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(count!=pos-1){
        temp=temp->next;
        count++;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
    
}
void display(node* head){
    node* temp=head;
    while(temp->next!=head){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    insertatTAil(head,1);
    insertatTAil(head,2);
    insertatTAil(head,3);
    insertatTAil(head,4);
    insertatTAil(head,5);
    insertatTAil(head,6);
    display(head);
    deletenode(head,3);
    display(head);
    deletenode(head,1);
    display(head);
    return 0;
}