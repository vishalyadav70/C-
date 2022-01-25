#include<bits/stdc++.h>
using namespace std;
// #define f(i,a,b) for(int i=a;i<b;i++);
// #define vi vector<int>;
bool compare(pair<int,int>p1,pair<int,int>p2){
    double v1=(double)p1.first/p1.second;
    double v2=(double)p2.first/p2.second;
    return v1>v2;
}
int main(){

    // int n;cin>>n;
    // vector<int> a(n);
    // for(int i=0;i<n;i++)  cin>>a[i];
    // int x;cin>>x;

    // sort(a.begin(),a.end(),greater<int>());
    // int ans=0;
    // for(int i=0;i<n;i++){
    //     ans+=x/a[i];
    //     x-=x/a[i]*a[i];
         
    // }
    
    // cout<<ans<<endl;
    // int n;
    // cin>>n;
    // vector<vector<int>>v;
    // for(int i=0;i<n;i++){
    //     int a,b;cin>>a>>b;
    //     v.push_back({a,b});
    // }
    // sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b){
    //   return a[1]<b[1];
    // });
    // int take=1;
    // int end=v[0][1];
    // for(int i=1;i<n;i++){
    //     if(v[i][0]<end){
    //         take++;
    //         end=v[i][0];
    //     }
    // }
    // cout<<take<<endl;
    // int n;cin>>n;
    // vector<pair<int,int>>a(n);
    // for(int i=0;i<n;i++){
    //     cin>>a[i].first>>a[i].second;
    // }
    // int w;cin>>w;
    // sort(a.begin(),a.end(),compare);
    // int ans=0;
    // for(int i=0;i<n;i++){
    //     if(w>=a[i].second){
    //         ans+=a[i].first;
    //         w-=a[i].second;
    //         continue;
    //     }
    //     double vw=(double)a[i].first/a[i].second;
    //     ans+=vw*w;
    //     w=0;
    //     break;
    // }
    // cout<<ans<<endl;
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    priority_queue<int,vector<int>,greater<int> >minheap;
    // vector<int>a(n);
    for(int i=0;i<n;i++){
        minheap.push(a[i]);
    }
    int ans=0;
    while(minheap.size()>1){
        int e1=minheap.top();
        minheap.pop();
        int e2=minheap.top();
        minheap.pop();
        ans+=e1+e2;
        minheap.push(e1+e2);
    }
    cout<<ans<<endl;
    return 0;
}