#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }

};
void insertatTail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void insertatHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}
bool search(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void deleteatHead(node* &head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteatHead(head);
        return;

    }
    node* todeleteo=head;
    head=head->next;
    delete todeleteo;
}
void deletion(node* &head,int key){
   node* temp=head;
    while(temp->next->data!=key){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
node* reverse(node* &head){
    node* pevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=pevptr;

        pevptr=currptr;
        currptr=nextptr;
    }
    return pevptr;
}
void makecylcle(node* &head,int pos){
    node* temp=head;
    node* newNode;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            newNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=newNode;


}
node* reve(node* &head){
    if(head==NULL || head->next==NULL){
        return head;

    }
    node* newhead=reve(head->next);
    head->next->next=head;
    head->next=NULL;
}
node* krev(node* &head,int k){
    node* pevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=pevptr;
        pevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
    head->next=krev(nextptr,k);
    }
    return pevptr;
}
bool detectCycle(node* head){
    node* slowptr=head;
    node* fastptr=head;
    while(fastptr!=NULL && fastptr->next!=NULL){
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;

        if(slowptr==fastptr){
            return true;
        }
    }
     return false;
}
void deformcycle(node* &head){
    node* slowptr=head;
    node* fastptr=head;
    do{
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;

    }while(slowptr!=fastptr);
    fastptr=head;
    while(fastptr->next!=slowptr->next){
        slowptr=slowptr->next;
        fastptr=fastptr->next;
    }
    slowptr->next=NULL;
}
int main()
{
    node* head=NULL;
    insertatTail(head,1);
    insertatTail(head,2);
    insertatTail(head,3);
    insertatTail(head,4);
    insertatTail(head,5);
    insertatTail(head,6);
    // insertatTail(head,7);
    // insertatHead(head,0);
    // display(head);
    // // cout<<search(head,3);
    // // cout<<search(head,5);
    // deletion(head,6);
    // display(head);
    // deleteatHead(head);
    // display(head);
    // // node* newhead=reverse(head);
    // // node* newhead=reve(head);
    // // display(newhead);
    // node* newhead=krev(head,2);
    // display(newhead);
    
    // cout<<detectCycle(head);
    makecylcle(head,3);
    //display(head);
    cout<<detectCycle(head);
    deformcycle(head);
    cout<<detectCycle(head);
    display(head);
    return 0;
}