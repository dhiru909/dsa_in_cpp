#include<bits/stdc++.h>
using namespace std;
void build(int ind, int low,int high,int arr[],int seg[],int orr){
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,arr,seg,!orr);
    build(2*ind+2,mid+1,high,arr,seg,!orr);
    if(orr){
        seg[ind]=seg[2*ind+1] | seg[2*ind+2];
    }
    else{
        seg[ind]=seg[2*ind+1] ^ seg[2*ind+2];
    }
}
void update(int ind, int low,int high,int seg[],int orr,int i,int val){
    if(low==high){
        seg[ind]=val;
        return;
    }
    int mid=(low+high)/2;
    if(i<=mid){
        update(2*ind+1,low,mid,seg,!orr,i,val);
    }
    else{
        update(2*ind+2,mid+1,high,seg,!orr,i,val);
    }
    if(orr){
        seg[ind]=seg[2*ind+1] | seg[2*ind+2];
    }
    else{
        seg[ind]=seg[2*ind+1] ^ seg[2*ind+2];
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    int arr[1<<n];
    int seg[4*(1<<n)];
    for(int i=0;i<(1<<n);i++){
        cin>>arr[i];
    }
    build(0,0,(1<<n)-1,arr,seg,n%2);
    while(m--){
        int p,b;
        cin>>p>>b;
        update(0,0,(1<<n)-1,seg,n%2,p-1,b);
        cout<<seg[0]<<endl;
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
    return 0;
}
