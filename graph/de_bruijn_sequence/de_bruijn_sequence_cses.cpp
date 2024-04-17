#include <bits/stdc++.h>
using namespace std;
unordered_set<string> hashs;
string ans;
int k;

void dfs(string u)
{
    for (int i = 0; i < k; i++)
    {
        auto e = u + to_string(i);
        if (!hashs.count(e))
        {
            hashs.insert(e);
            dfs(e.substr(1));
            ans += to_string(i);
        }
    }
}

string crackSafe(int n, int _k)
{
    k = _k;
    string start(n - 1, '0');
    dfs(start);
    return ans + start;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
    freopen("errorf.err", "w", stderr);
#endif
    int n;
    cin >> n;
    k = 2;
    // string start(n - 1, '0');
    // dfs(start);
    cout<<crackSafe(n,k)<<'\n';
}








/*
! giving TLE 

#include<bits/stdc++.h>
using namespace std;
int n,k;
int total;
string finalAns = "";
bool visited[32800];
int counter = 0;
void dfs(string s,string ans){
    if(counter == total){
        int ind = 0;
        string newAns = "";
        newAns+=ans.substr(0,n);
        ind = n+n-1;
        int ansSize = ans.size();
        while(ind<ansSize){
            newAns+=ans[ind];
            ind+= n;
        }
        finalAns = newAns;
        return ;
    }else{
        string temp  = s.substr(1);
        for(int i=0;i<k;i++){
            char c= i+'0';
            string newStr = temp+c;
            int newStrInt = stoi(newStr);
            if(visited[newStrInt]){
                continue;
            }
            visited[newStrInt]=1;
            counter++;
            
            dfs(newStr,ans+newStr);
            counter--;
            visited[newStrInt]=0;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
    freopen("errorf.err", "w", stderr);
#endif
    // int n;
    cin>>n;
    k=2;
    total=pow(k,n);
    string s="";
    for(int i=0;i<n;i++) s+= '0';
    visited[stoi(s)]=1;
    counter++;
    dfs(s,s);
    cout<<finalAns<<'\n';
 
 
}

*/