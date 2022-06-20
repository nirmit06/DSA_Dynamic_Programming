#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
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

    string temp=to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));
    if(mp.find(temp)!=mp.end()){
        return mp[temp];
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
    return mp[temp]=ans;
    
}

int main(){
    mp.clear();
    string s;
    cin>>s;

    cout<<BP(s,0,s.length()-1,true)<<"\n";
}