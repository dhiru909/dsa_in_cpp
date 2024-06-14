#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
    freopen("errorf.err", "w", stderr);
#endif
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool flag=0;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            if(i==0 and temp!=1){
                flag=1;
            }
        }
        if(flag){
            cout<<"No"<<'\n';

        }else{
            cout<<"Yes"<<'\n';
        }
    }
}