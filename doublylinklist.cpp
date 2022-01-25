#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;

    }

};
void insertHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    if(head!=NULL){
    head->prev=n;
    }

    head=n;
}
void insertTail(node* &head,int val){

    if(head==NULL){
        insertHead(head,val);
        return;
    }
    node* n=new node(val);
    node* temp=head;
    while(temp->next!=NULL){
            temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void deletehead(node* &head){
    node* todel=head;
    head=head->next;
    head->prev=NULL;
    delete todel;
}
void deleteN(node* &head,int pos){

    if(pos==1){
        deletehead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;

    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
        }

    delete temp;


}
int nodelen(node* head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
}
node* appendk(node* &head,int pos){
    node* newTail;
    node* newHead;
    node* tail=head;
    
    int l=nodelen(head);
    int count=1;
    pos=pos%l; 
    while(tail->next!=NULL){
        if(count==l-pos){
            newTail=tail;

        }
        if(count==l-pos+1){
            newHead=tail;
        }
        tail=tail->next;
        count++;
    }
    newTail->next=NULL;
    tail->next=head;


}
node* merge(node* &head1,node* &head2){
    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(-1);
    node* p3=dummyNode;
    
    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;

    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummyNode->next;
}
node* mergerec(node* &head1,node* &head2){
    node* result;
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data<head2->data){
        result=head1;
        result->next=mergerec(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergerec(head1,head2->next);
    }
    return result;
}
int intersectionPoint(node* &head1,node* &head2){
    int l1=nodelen(head1);
    int l2=nodelen(head2);
    int d=0;
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    while(ptr1!=NULL && ptr2==NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}
void intersection(node* &head1,node* &head2,int pos){
    node* temp1=head1;
    pos--;
    while(pos){
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(pos){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}
int main(){
        node* head1=NULL;
        node* head2=NULL;
        insertTail(head1,1);
        insertTail(head1,4);
        insertTail(head1,5);
        insertTail(head1,7);
        insertTail(head2,2);
        insertTail(head2,3);
        insertTail(head2,6);
        display(head1);
        display(head2);
        node* new1=mergerec(head1,head2);
        display(new1);
    return 0;
}