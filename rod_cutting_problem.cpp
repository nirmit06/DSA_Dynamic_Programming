#include<bits/stdc++.h>
using namespace std;
int t[10005][10005];
int main(){
    int n;
    cin>>n;
    int N;
    cin>>N;

    int len[n];
    for(int i =0;i<n;i++){
        cin>>len[i];
    }

    int price[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<N+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<N+1;j++){
            if(len[i-1]<=j){
                t[i][j]=max(price[i-1]+t[i][j-len[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        {
            for (int j = 0; j <= N; j++)
                cout << t[i][j] << " ";
        }
        cout << endl;
    }

    cout<<t[n][N]<<"\n";
    return 0;
}