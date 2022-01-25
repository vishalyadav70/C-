#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void preorder(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}
Node* buildTree(int preorder[],int inorder[],int start,int end){
    static int idx=0;
    if(start>end){
        return NULL;
    }
    int curr=preorder[idx];
    idx++;
    Node* node=new Node(curr);
    if(start==end){
        return node;
    }
    int pos=search(inorder,start,end,curr);
    node->left=buildTree(preorder,inorder,start,pos-1);
    node->right=buildTree(preorder,inorder,pos+1,end);
    return node;
}
int search1(int inorder[],int start,int end,int val){
    for(int i=start;i<=end;i++){
        if(inorder[i]==val){
            return i;
        }
    }
    return -1;
}
Node* buildTree1(int postorder[],int inorder[],int start,int end){
    static int idx=4;
    if(start>end){
        return NULL;
    }
    int val=postorder[idx];
    idx--;
    Node* curr=new Node(val);
    if(start==end){
        return curr;
    }
    int pos=search1(inorder,start,end,val);
    curr->right=buildTree1(postorder,inorder,pos+1,end);
    curr->left=buildTree1(postorder,inorder,start,pos-1);

    return curr;
}
void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right );
}
void levelordertrav(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            if(node->right){
                q.push(node->right);
            }
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}
int sumklevel(Node* root,int k){
    queue<Node*>q;
    if(root==NULL){
        return -1;
    }
    q.push(root);
    q.push(NULL);
    int level=0;int sum=0;

    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            if(level==k){
            sum+=node->data;
            }
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;

}
int countnodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return countnodes(root->left)+countnodes(root->right)+1;
}
int sumofnodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return sumofnodes(root->left)+sumofnodes(root->right)+root->data;
}
int calcheight(Node* root){
    if(root==NULL){
        return 0;
    }
    int lefhri=calcheight(root->left)+1;
    int reghri=calcheight(root->right)+1;
    return max(lefhri,reghri);
}
int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int lefheight=calcheight(root->left);
    int regheight=calcheight(root->right);
    int currdia=lefheight+regheight+1;

    int ldia=diameter(root->left);
    int rdia=diameter(root->right);

    return max(currdia,max(ldia,rdia));

}
void sumrep(Node* root){
    if(root==NULL){
        return;
    }
    sumrep(root->left);
    sumrep(root->right);
    if(root->left!=NULL){
        root->data+=root->left->data;
    }
    if(root->right!=NULL){
        root->data+=root->right->data;
    }

    
}
bool isbalanced(Node* root){

    if(isbalanced(root->left)==false){
        return false;
    }
        if(isbalanced(root->left)==false){
        return false;
    }
    int lh=calcheight(root->left);
    int rh=calcheight(root->right);
    if(abs(lh-rh)<=1){
        return true;
    }
    else return false;
}
void rightview(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* curr=q.front();
            q.pop();
            if(i==n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}
void leftview(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* curr=q.front();
            q.pop();
            if(i==0){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}
Node* LCA(Node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* left=LCA(root->left,n1,n2);
    Node* right=LCA(root->right,n1,n2);
    if(left!=NULL && right!=NULL){
        return root;
    }
    if(left==NULL && right==NULL){
        return NULL;
    }
    if(left!=NULL){
        return LCA(root->left,n1,n2);
    }
    if(right!=NULL){
        return LCA(root->right,n1,n2);
    }
}
int finddis(Node* root,int k,int dis){
    if(root==NULL){
        return -1;
    }
    if(root->data==k){
        return dis;
    }
    int left=finddis(root->left,k,dis+1);
    if(left!=-1){
        return left;
    }
    return finddis(root->right,k,dis+1);
}
int disbwnodes(Node* root,int n1,int n2){
    Node* lca=LCA(root,n1,n2);
    int d1=finddis(root,n1,0);
    int d2=finddis(root,n2,0);
    return d1+d2;
}
void faltten(Node* root){
    if(root==NULL || ((root->left)==NULL && (root->right)==NULL))
    if(root->left!=NULL){
        faltten(root->left);
        Node* temp=root->right;
        root->right=root->left;
        root->left=NULL;
        Node* t=root->right;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right=temp;
    }
    faltten(root->right);
    
}
//case1
void printSubtreenodes(Node* root,int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printSubtreenodes(root->left,k-1);
    printSubtreenodes(root->right,k-1);

}
//case2
int printnodesatk(Node* root,Node* target,int k){
    if(root==NULL) return -1;
    if(root==target){
        printSubtreenodes(root,k);
        return 0;
    }
    int dl=printnodesatk(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSubtreenodes(root->right,k-dl-2);
        }
        return 1+dl;
    }
    int dr=printnodesatk(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSubtreenodes(root->left,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
}
int lowestcommonAncestor(Node* root,int n1,int n2){
    vector<int>path1,path2;
    if(!getpath(root,n1,path1) || !getpath(root,n2,path2)){
        return -1;
    }
    int pc;
    for(pc=0;pc<path1.size() && pc<path2.size();pc++){
        
    }
}
int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    // root->left->right=new Node(3);
    // root->right->left=new Node(6);
    // root->right->right=new Node(6);
    // // preorder(root);
    // postorder(root);
    // int preorder[]={1,2,4,3,5};
    // int inorder[]={4,2,1,5,3};
    // int postorder[]={4,2,5,3,1};
    // Node* root=buildTree1(postorder,inorder,0,4);
    // Node* root=sumrep(root);
    // preorder(root);
    // cout<<endl;
    // sumrep(root);
    // preorder(root);
    // levelordertrav(root);
    // cout<<sumklevel(root,2);
    // cout<<sumrep(root)<<endl;
    // if(isbalanced(root)){
    //     cout<<"BALANCED";
    // }
    // else{
    //     cout<<"NOT Balanced";
    // rightview(root);
    // cout<<endl;
    // leftview(root);
    // cout<<disbwnodes(root,4,5);
    // faltten(root);
    // inorder(root);
    printnodesatk(root,root->left,1);

    /*  1
        /\
        2 3
        /\ /\
        4 5 6 7
    
    
    */
    return 0;
}