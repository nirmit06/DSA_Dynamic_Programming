#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;j--;
    }
    return true;
}
int t[10005][10005];
int PP(string s,int i,int j){
    if(i>=j){
        return 0;
    }
    if(t[i][j]!=-1) return t[i][j];
    if(isPalindrome(s,i,j)==true){
        t[i][j]=0;
    return 0;
    }
    
    int mn=INT_MAX;
    int left,right;
    for(int k=i;k<=j-1;k++){
        // int temp=1 +PP(s,i,k)+PP(s,k+1,j); //not optimized
        if(t[i][k]!=-1){
            left=t[i][k];
        }
        else{
            left=PP(s,i,k);
            t[i][k]=left;
        }

        if(t[k+1][j]!=-1){
            right=t[k+1][j];
        }
        else{
            right=PP(s,k+1,j);
            t[k+1][j]=right;
        }
        int temp=1+left+right;
        mn=min(mn,temp);
    }
    return t[i][j]=mn;
}

int main(){
    memset(t,-1,sizeof(t));
    string s;
    cin>>s;

    cout<<PP(s,0,s.length()-1)<<"\n";
    return 0;
}