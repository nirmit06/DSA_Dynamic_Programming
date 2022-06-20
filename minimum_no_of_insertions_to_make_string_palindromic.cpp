#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    cin>>a;
    string b=a;
    reverse(b.begin(),b.end());
    int x=a.size();
    int y=b.size();
    int t[x+1][y+1];

    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }

    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(a[i-1]==b[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    cout<<x-t[x][y]<<"\n";
}