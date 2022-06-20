#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main()
{
int n,w;
cin>>n>>w;
int value[n],weight[n];
for(int i=0;i<n;i++){
    cin>>weight[i]>>value[i];
}
int t[n+1][w+1];
for(int i=0;i<n+1;i++){
    for(int j=0;j<w+1;j++){
        if(i==0 || j==0)
        t[i][j]=0;
    }
}

for(int i=1;i<n+1;i++){
    for(int j=1;j<w+1;j++){
        if(weight[i-1]<=j){
            t[i][j]=max(value[i-1]+t[i-1][j-weight[i-1]],t[i-1][j]);
        }
        else{
            t[i][j]=t[i-1][j];
        }
    }
}
cout<<t[n][w]<<"\n";
return 0;
}