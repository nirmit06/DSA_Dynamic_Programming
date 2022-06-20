#include<bits/stdc++.h>
using namespace std;
int t[10005][10005];
int main(){
    int n;
    cin>>n;
    int wt;
    cin>>wt;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    int val[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<wt+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<wt+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=max(val[i-1]+t[i][j-arr[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        {
            for (int j = 0; j <= wt; j++)
                cout << t[i][j] << " ";
        }
        cout << endl;
    }

    cout<<t[n][wt]<<"\n";
    return 0;
}