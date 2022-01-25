#include<bits/stdc++.h>
// #include<vector>
using namespace std;
struct Node
{
    int data;
    Node*left,*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};
Node* insertbst(Node* root,int val){
    // Node* newnode=new Node(val);
    if(root==NULL){
        return new Node(val);
    }
    if(root->data>val){
        root->left=insertbst(root->left,val);;
    }
    else{
        root->right=insertbst(root->right,val);
    }
    return root;
    
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* searching(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data>key){
        searching(root->left,key);
    }
    
        searching(root->right,key);
    
}
Node* inordersucc(Node* root){
    Node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node* deletion(Node* root,int key){
    
    if(root->data>key){
        root->left=deletion(root,key);

    }
    else if(root->data<key){
        root->right=deletion(root,key);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        Node* temp=inordersucc(root->right);
        root->data=temp->data;
        root->right=deletion(root->right,temp->data);

    }
    return root;
}
Node* constructionbst(int preorder[],int* preorderidx,int key,int min,int max,int n){
    Node* root=NULL;
    if(*preorderidx>=n){
        return NULL;
    }
    if(key>min && key<max){
        root=new Node(key);
        *preorderidx=*preorderidx+1;
        if(*preorderidx<n){
            constructionbst(preorder,preorderidx,preorder[*preorderidx],min,key,n);
        }
        if(*preorderidx<n){
            constructionbst(preorder,preorderidx,preorder[*preorderidx],key,max,n);
        }
    }
    
    return root;
}
void printpreorder(Node* root){
    if(root==0){
        return;
    }
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);

}
bool bstornot(Node* root,Node* min=NULL,Node* max=NULL){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    bool lvalid=bstornot(root->left,min,root);
    bool rvalid=bstornot(root->right,root,max);
    return lvalid and rvalid;

}
Node* sortedarraytobst(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    Node* root=new Node(arr[mid]);
    root->left=sortedarraytobst(arr,start,mid-1);
    root->right=sortedarraytobst(arr,mid+1,end);
    return root;
}
// vector<Node*>constructtrees(int start,int end){
//     vector<Node*>trees;
//     if(start>end){
//         trees.push_back(NULL);
//         return;
//     }
//     for(int i=start;i<=end;i++){
//         vector<Node*>v1=constructtrees(start,i-1);
//         vector<Node*>v2=constructtrees(i+1,end);

//         for(int j=0;j<v1.size();j++){
//             vector<Node*>left=v1[j];
//             for(int k=0;k<v2.size();k++){
//                 vector<Node*>right=rightSubtrees[k];
//                 Node* newnode=new Node(i);
//                 newnode->left=left;
//                 newnode->right=right;
//                 trees.push_back(newnode);
//             }
//         }
//     }
//     return trees;
// }
bool Identicalornot(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if(root1==NULL || root2==NULL){
        return false;
    }
    else{
        bool cond1=(root1->data==root2->data);
        bool cond2=Identicalornot(root1->left,root2->left);
        bool cond3=Identicalornot(root1->right,root2->right);
        if(cond1 && cond2 && cond3){
            return true;
        }
        return false;
    }
}
int main(){
    // Node* root=new Node(12);
    // root->left=new Node(9);
    // root->right=new Node(15);
    // root->left->left=new Node(5);
    // root->left->right=new Node(10);

    // root=insertbst(root,5);
    // insertbst(root,1);
    // insertbst(root,3);
    // insertbst(root,4);
    // insertbst(root,2);
    // insertbst(root,7);
    // inorder(root);
    // cout<<endl;
    // // if(searching(root,5)==NULL){
    // //     cout<<"key does not exists"<<endl;
    // // }
    // // else
    // // cout<<"Key exists"<<endl;

    // root=deletion(root,5);
    // inorder(root);
    // int preorder[]={10,2,1,13,11};
    // int n=5;
    // int preorderidx=0;
    // Node* root=constructionbst(preorder,&preorderidx,preorder[0],INT_MIN,INT_MAX,n);
    // printpreorder(root);
    // Node* root1=new Node(5);
    // root1->left=new Node(2);
    // root1->right=new Node(8);
    // if(bstornot(root1,NULL,NULL)){
    //     cout<<" is bst";
    // }
    // else cout<<"not bst";
    // int arr[]={10,20,30,40,50};
    // Node* root=sortedarraytobst(arr,0,4);
    // vector<Node*>totaltrees=constructtrees(1,3);
    // for(int i=0;i<totaltrees.size();i++){
    //     cout<<(i+1)<<":";
    // printpreorder(totaltrees[i]);
    // cout<<endl;
    // }
    /*
            2
            /\
            1 3
    */
   Node* root1=new Node(2);
   root1->left=new Node(1);
   root1->right=new Node(3);
    Node* root2=new Node(2);
   root2->left=new Node(1);
   root2->right=new Node(4);

   if(Identicalornot(root1,root2)){
       cout<<"Both BST are identical"<<endl;
   }
   else{
       cout<<"BSTs are not identical"<<endl;

   }
    return 0;
}