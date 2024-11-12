#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef LOCAL
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
    freopen("errorf.err", "w", stderr);
#endif
    
    int t;
    cin>>t;
    int arr[200010];
    while(t--){
        int n,k;
        cin>>n>>k;
        int siz = n*k;
        for(int i=1;i<=siz;i++){
            cin>>arr[i];
        }
        long long ans =0;
        int half = n/2;
        int start  = ((n*k)-half);
        // cout<<"case "<<t<<endl;
        while(k--){
            // cout<<start<<" ";
            ans+=arr[start];
            start = start -half-1;
        }
        cout<<ans<<endl;

    }
}