#include<bits/stdc++.h>
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
void GetVerticalOrder(Node* root,int hdis,map<int,vector<int>>&m){
    if(root==NULL){
        return;
    }
    m[hdis].push_back(root->data);
    GetVerticalOrder(root->left,hdis-1,m);
    GetVerticalOrder(root->right,hdis+1,m);

}
int main(){
//    Node* root=new Node(10);
//    root->left=new Node(7);
//    root->left->left=new Node(3);
//    root->left->right=new Node(11);
//    root->right=new Node(4);
//    root->right->left=new Node(14);
//    root->right->right=new Node(6);

//    map<int,vector<int>>m;
//    int hdis=0;
//    GetVerticalOrder(root,hdis,m);

//     map<int,vector<int>> :: iterator it;
//     for(it=m.begin();it!=m.end();it++){ 
//         cout<<it->first<<':';
//         for(int i=0;i<(it->second).size();i++){
//             cout<<(it->second)[i]<<" ";
//         }cout<<endl;

//     }
// int n;cin>>n;
// int a[n];
// for(int i=0;i<n;i++) cin>> a[i];
// map<int,int>cnt;
// int prevsum=0;
// for(int i=0;i<n;i++){
//     prevsum+=a[i];
//     cnt[prevsum]++;
// }
// int ans;
// map<int,int> :: iterator it;
// for(it=cnt.begin();it!=cnt.end();it++){

// }
// int n,k;cin>>n>>k;
// int a[n];
// for(int i=0;i<n;i++) cin>>a[i];
// int s=0,ans=INT_MAX;
// for(int i=0;i<n;i++){
//     s+=a[i];
// }
// ans=min(ans,s);
// for(int i=1;i<n-k+1;i++){
//     s-=a[i-1];
//     s+=a[i+k-1];
//     ans=min(ans,s);
// }
// cout<<ans<<endl;
int n,k;cin>>n>>k;
int a[n];
for(int i=0;i<n;i++)    cin>>a[i];
map<int,int>freq;
for(int i=0;i<n;i++){
    int preSize=freq.size();
    if(a[i]==0 && preSize==k){
        break;
    }
    freq[a[i]]++;
}
vector<int,int>v;
map<int,int>::iterator it;
for(it=freq.begin();it!=freq.end();it++){
    if(it->second!=0){
        v.push_back(it->second,it->first);
    }
}

}
