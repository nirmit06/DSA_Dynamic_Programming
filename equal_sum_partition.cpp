#include <bits/stdc++.h>

using namespace std;
bool t[10005][10005];
bool subSetSum(int arr[],int sum,int n){

    for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
        if(i==0){
            t[i][j]=0;
        }
        if(j==0){
            t[i][j]=1;
        }
        
    }
}

for(int i=1;i<n+1;i++){
    for(int j=1;j<sum+1;j++){
      if(arr[i-1]<=j){
          t[i][j]= (t[i-1][j-arr[i-1]] || t[i-1][j]) ;
      }
      else if(arr[i-1]>j){
          t[i][j]=t[i-1][j];
      }
    }
}
for (int i = 0; i <= n; i++){
     {
       for (int j = 0; j <= sum; j++)
          cout<<t[i][j]<<" ";
     }
cout<<endl;
 }
    return t[n][sum];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    if(sum%2!=0){
        cout<<"No"<<"\n";
    }
    else{
        if(subSetSum(arr,sum/2,n)==true){
            cout<<"Yes"<<"\n";
        }
        else{
            cout<<"No"<<"\n";
        }
    }
     
    return 0;
}