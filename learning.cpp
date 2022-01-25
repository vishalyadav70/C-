#include<bits/stdc++.h>
using namespace std;
int binarySearch(int a[],int n,int b)
{
   int s=0,e=n;
   while(s<=e){
       int mid=(s+e)/2;
       if(a[mid]==b){
           return mid; 
       }
       else if(a[min]>b){
           e=mid-1;
       }
       else{
            s=mid+1;
       }
   }

   return -1;
}
int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int b;cin>>b;
    cout<<binarySearch(a,n,b)<<endl;
    return 0;
}