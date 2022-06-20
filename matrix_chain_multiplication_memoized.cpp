#include<bits/stdc++.h>
using namespace std;
int t[10005][10005];
int MCM(int arr[],int i,int j){
    if(i>=j)
    return 0;
    if(t[i][j]!=-1) return t[i][j];
    int mn=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp_ans=MCM(arr,i,k)+MCM(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        mn=min(mn,temp_ans);
    }
    return t[i][j]=mn;
}

int main(){
    memset(t,-1,sizeof(t));
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<MCM(arr,1,n-1)<<"\n";

}