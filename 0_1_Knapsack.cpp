#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int t[10005][10005];
int Knapsack(int val[],int wt[],int w,int n){
    if(n==0 || w==0){
        return 0;
    }
    if(t[n][w]!=-1) return t[n][w];

    if(wt[n-1]<=w){
        return t[n][w]=max(val[n-1]+Knapsack(val,wt,w-wt[n-1],n-1),Knapsack(val,wt,w,n-1));
    }
    else{
        return t[n][w]=Knapsack(val,wt,w,n-1);
    }
}

int main()
{
memset(t,-1,sizeof(t));
int n,w;
cin>>n>>w;
int value[n],weight[n];
for(int i=0;i<n;i++){
    cin>>weight[i]>>value[i];
}

cout<<Knapsack(value,weight,w,n);
return 0;
}