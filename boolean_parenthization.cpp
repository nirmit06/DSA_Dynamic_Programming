#include<bits/stdc++.h>
using namespace std;

int BP(string s,int i,int j,bool isTrue){
    if(i>j){
        return 0;
    }

    if(i==j){
        if(isTrue==true)
        return s[i]=true;
        else 
        return s[i]=false;
    }
    int ans=0;
    for(int k=i+1;k<=j-1;k+=2){
        int lT=BP(s,i,k-1,true);
        int lF=BP(s,i,k-1,false);
        int rT=BP(s,k+1,j,true);
        int rF=BP(s,k+1,j,false);
        // cout<<lT<<" "<<lF<<" "<<rT<<" "<<rF<<"\n";
        if(s[k]=='&'){
            if(isTrue==true){
                ans+=(lT*rT);
            }
            else{
                ans+=((lT*rF)+(lF*rF)+(lF*rT));
            }
            
        }
        else if(s[k]=='|'){
            if(isTrue==true){
                ans+=((lT*rF)+(lT*rT)+(lF*rT));
                
            }
            else{
                ans+=(lF*rF);
            }
        }
        else if(s[k]=='^'){
            if(isTrue==true){
                ans+=((lF*rT)+(lT*rF));
            }
            else{
                ans+=((lT*rT)+(lF*rF));
            }
        }
    }
    return ans;
    
}

int main(){
    string s;
    cin>>s;

    cout<<BP(s,0,s.length()-1,true)<<"\n";
}