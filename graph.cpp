#include<bits/stdc++.h>
using namespace std;
vector<bool>vis;
int n,m;
vector<vector<int>>adj;
vector<int>components;
int get_comp(int idx){
    if(vis[idx]){
        return 0;
    }
    vis[idx] = true;
    int ans=1;
    for(auto i: adj[idx]){
        ans+=get_comp(i);
        vis[i]=true;
    }
    return ans;
}
int main(){
    cin>>n>>m;
    adj=vector<vector<int>>(n);
    vis=vector<bool>(n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            components.push_back(get_comp(i));
        }
    }
    for(auto i:components){
        cout<<i<<" ";
    }
    return 0;
}



































































































// #include<bits/stdc++.h>
// using namespace std;
// vector<int> bfs(int V,vector<int>adj[]){
//     vector<int>bfs;
//     vector<int>vis(V+1,0);
//     for(int i=1;i<=V;i++){
//         if(!vis[i]){
//             queue<int>q;
//             q.push(i);
//             vis[i]=1;
//             while(!q.empty()){
//                 int node=q.front();
//                 q.pop();
//                 bfs.push_back(node);
//                 for(auto it : adj[node]){
//                     if(!vis[it]){
//                         q.push(it);
//                         vis[it]=1;
//                     }
//                 }
//             }
//         }

//     }
//     return bfs;
// }
// class solution{
//     void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>dfs_store){ 
//         dfs_store.push_back(node);
//         vis[node]=1;
//         for(auto it: adj[node]){
//             if(!vis[it]){
//                 dfs(it,vis,adj,dfs_store);
//             }
//         }

//     }

//     public:
//     vector<int>dfsgraph(int V,vector<int>adj[]){
//         vector<int>dfs_store;
//         vector<int>vis(V+1,0);
//         for(int i=1;i<=V;i++){
//             if(!vis[i]){
//                 dfs(i,vis,adj,dfs_store);
//             }
//         }
//     }
// };
// // class Solution{
// //     public:
// //     bool checkForCycle(int node,int parent,vector<int>&vis,vector<int>adj[]){
// //         vis[node]=1;
// //         for(auto it: adj[node]){
// //             if(!vis[it]){
// //                 if(checkForCycle(it,node,vis,adj))
// //                     return true;
// //             }else if(it!=parent){return true;}
// //         }
// //         return false;
// //     }
// //     public:
// //     bool isCycle(int V,vector<int>adj[]){
// //         vector<int>vis(V+1,0);
// //         for(int i=0;i<=V;i++){
// //             if(!vis[i]){
// //                 if(checkForCycle(i,-1,vis,adj))
// //                     return true;
// //             }
// //         }
// //     }

// // };
// class Solution{
//     public:
//     bool checkForCycle(int node,int parent,vector<int>&vis,vector<int>adj[]){
//             queue<pair<int,int>>q;
//             vis[node]=true;
//             q.push({node,-1});
//             while(!q.empty()){
//                 int nod=q.front().first;
//                 int parent=q.front().second;
//                 q.pop();

//                 for(auto it: adj[node]){
//                     if(!vis[it]){
//                         vis[it]=true;
//                         q.push({it,nod});
//                     }else if(it!=parent){
//                         return true;
//                     }
//                 }
//             }
//             return false;
//     } 

//     public:
//     bool isCycle(int V,vector<int>adj[]){
//         vector<int>vis(V+1,0);
//         for(int i=1;i<=V;i++){
//             if(!vis[i]){
//                 checkForCycle(i,-1,vis,adj);
//             }
//         }
//     }
// };
// bool bipartitedfs(int node,vector<int>adj[],int colour[]){
//     if(colour[node]==-1) colour[node]=1;
//     for(auto it: adj[node]){
//         if(colour[it]==-1){
//              colour[it]=1-colour[node];
//              if(!bipartitedfs(it,adj,colour)){
//                  retutn false;
//              }
//              }else if(colour[it]==colour[node]) return false;
//     }
//     return true;
// }
// bool bipartitebfs(int src,vector<int>adj[],int colour[]){
//     queue<int>q;
//     q.push(src);
//     colour[src]=1;
//     while(!q.empty()){
//         int node=q.front();
//         q.pop();
//         for(auto it: adj[node]){
//             if(colour[it]==-1){
//                 colour[it]=1-colour[node];
//                 q.push(it);
//             }else if(colour[it]==colour[node])
//                 return false;
//         }
//     }
//     return true;
// }
// bool checkBipartite(vector<int>adj[],int n){
//     int colour[n];
//     memset(colour,0,sizeof(colour));
//     for(int i=0;i<=n;i++){
//         if(colour[i]==-1){ 
//             if(!bipartitedfs(i,adj,colour)){
//                 return false;
//             }
//         }
//     }
//     return true;
// }
// int main(){
//     int V,E;cin>>V>>E;
//     vector<int>adj[V+1];
//     for(int i=0;i<E;i++){
//         int u,v;cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     if(!checkBipartite(adj,V)){
//         cout<<"Yes"<<endl;
//     }
//     else cout<<"No"<<endl;
//     return 0;
    
    
    
// }