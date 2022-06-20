#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n;
cin>>n;
int t[100][100];
int arr[n];
int sum;
cin>>sum;
for(int i=0;i<n;i++){
    cin>>arr[i];
}

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
cout<<t[n][sum]<<"\n";

return 0;
}