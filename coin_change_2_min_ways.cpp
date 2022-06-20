#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX-1;
int main(){
    int n;
    cin>>n;

    int sum;
    cin>>sum;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int t[n+1][sum+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j]=INF;
            }
            else{
                t[i][j]=0;
            }
        }
    }


        for(int j=1;j<sum+1;j++){
            if(j%arr[0]==0){
                t[1][j]=j/arr[0];
            }
            else{
                t[1][j]=INF;
            }
        }
    

    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=sum){
                t[i][j]=min(t[i-1][j],1+t[i][j-arr[i-1]]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
            for (int j = 0; j <= sum; j++)
            {
            if(t[i][j]==INT_MAX-1){
                cout<<'I'<<" ";
            }
            else{
                cout << t[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout<<t[n][sum]<<"\n";

    return 0;
}