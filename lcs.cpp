#include<bits/stdc++.h>
using namespace std;
string plcsubstring(string X,string Y){
    int m=X.length();
    int n=Y.length();
    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(X[i-1]==Y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string s="";
    int i=m,j=n;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            s.push_back(X[i-1]);
            i--;j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }
            else{i--;}
        }
    }
    reverse(s.begin(), s.end());
    return s;
}
int main(){
    string X,Y;
    cin>>X>>Y;
    cout<<plcsubstring(X,Y);
}
// int static dp[1001][1001];
// int lcfrecursive(string X,string Y,int n,int m){
//     if(n==0 || m==0){
//         return 0;
//     }
//     if(X[n-1]==Y[n-1]){
//         return 1+lcfrecursive(X,Y,n-1,n-2);
//     }
//     else{
//         return max(lcfrecursive(X,Y,n,m-1),lcfrecursive(X,Y,n-1,m));
//     }
// }
// int lcfmem(string X,string Y,int n,int m){
//     if(n==0 || m==0){
//         return 0;
//     }
//     if(dp[n][m]!=-1){
//         return dp[n][m];
//     }
//     if(X[n-1]==Y[n-1]){
//         dp[n][m]=1+lcfmem(X,Y,n-1,m-1);
//     }
//     else{
//         dp[n][m]=max(lcfmem(X,Y,n-1,m),lcfmem(X,Y,n,m-1));
//     }
//     return dp[n][m];
// }
// int main(){
//     string X,Y;
//     cin>>X>>Y;
//     int n=X.size();
//     int m=Y.size();
//     memset(dp,-1,sizeof(dp));
//     cout<<lcfmem(X,Y,n,m)<<endl;
// }


































































// // #include<bits/stdc++.h>
// // using namespace std;
// // int fdp(int n){
// //     int dp[10000007];
// //     dp[0]=0;
// //     dp[1]=0;
// //     dp[2]=1;
// //     for(int i=3;i<n;i++){
// //         dp[i]=fdp(i-1)+fdp(i-2);
// //     }
// //     cout<<dp[n];

// // }

// // int main(){
// //     int n;cin>>n;
// //     cout<<fdp(n);
// // }








// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // #define vi vector<int>;
// // // #define rep(i,a,b) for(int i=a;i<b;i++)
// // // const int N=1e5+2,MOD=1e9+7;
// // // int dp[N];
// // // int minsq(int n){
// // //     if(dp[n]!=MOD){
// // //         return dp[n];
// // //     }
// // //     for(int i=1;i*i<=n;i++){
// // //         dp[n]=min(dp[n],1+minsq(n-i*i));
// // //     }

// // //     return dp[n];

// // // }
// // // int main(){
    
// // //     /*Fibanico no 
    
// // //     int n;
// // //     cin>>n;
// // //     int dp[n+1];
// // //     dp[0]=0;
// // //     dp[1]=0;
// // //     dp[2]=1;
// // //     for(int i=3;i<=n;i++){
// // //         dp[i]=dp[i-1]+dp[i-2];
// // //     }
// // //     cout<<dp[n]<<endl;
// // //     */
// // // rep(i,0,N){
// // //        dp[i]=MOD;
// // //    }

// // //    int n;cin>>n;
   
// // //    cout<<minsq(n)<<endl;

   
// // //     return 0;
// // // }