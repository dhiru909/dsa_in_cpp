    #include <bits/stdc++.h>
    #define ll long long
    #define pb push_back
    #define ff first
    #define ss second
    #define mp make_pair
    #define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    using namespace std;
     
    int main()
    {   
        ios;
        #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll t;
        cin>>t;
        while(t--) {
            ll n,flag=0;
            cin>>n;
            vector < ll > v(n);
            for(ll i = 0 ; i < n ; i++) 
                cin>>v[i];
            for(ll i = 0 ; i <  n ; i++) {
                for(ll j = i+1 ; j < n; j++) {
                    if(__gcd(v[i],v[j]) <= 2) {
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 1) 
               cout<<"Yes";
            else
               cout<<"No";
            cout<<endl;
        }
     
        return 0;     
     }