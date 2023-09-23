#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int t;
cin>>t;
while(t--){

}
}
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>hashS;
        unordered_map<char,int>hashT;
        for(auto &c:t){
            hashT[c]++;
        }
        int ct=0,st=0,en=0,n=hashT.size();
        int ans=INT_MAX,ansInd=-1;
        while(st<=en and en< s.size()){
            if(++hashS[s[en]]==hashT[s[en]])ct++;
            if(ct==n){
                while(ct==n){
                    if(ans>en-st+1){
                        ans=min(ans,en-st+1);
                        ansInd=st;
                    }
                    if(hashT.find(s[st])==hashT.end()){
                        st++;
                    }else{
                        hashS[s[st]]--;
                        if(hashS[s[st]]<hashT[s[st]])ct--;
                        st++;
                    }
                }
            }
            en++;
        }
        return ansInd==-1?"":s.substr(ansInd,ans);
        
    }
};