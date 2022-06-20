#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
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
    
     for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }
    int i=a.length(),j=b.length();
    string s="";

    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            s.push_back(a[i-1]);
            i--;j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                s.push_back(b[j-1]);
                j--;
            }
            else{
                s.push_back(a[i-1]);
                i--;
            }
        }
    }

    while(i>0){
        s.push_back(a[i-1]);
        i--;
    }

    while(j>0){
        s.push_back(b[j-1]);
        j--;
    }
    reverse(s.begin(),s.end());
    cout<<s<<"\n";
}