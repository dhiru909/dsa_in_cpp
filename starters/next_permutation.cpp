//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int>& arr){
        // code here
        int n=N;
        int prev=-1;
        int index=0;
        for(int i=n-1;i>0;i--){
            if(arr[i]>arr[i-1]){
                prev=i-1;
                // cout<<prev<<" ";
                break;
            }
        }
        // cout<<prev;
        if(prev==-1){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        else{
            index=prev+1;
            for(int i=index;i<n;i++){
                if(arr[i]>arr[prev]&&arr[index]>arr[i]){
                    index=i;
                }
            }
            swap(arr[index],arr[prev]);
            reverse(arr.begin()+prev+1,arr.end());
            return arr;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cout<<"Start:";
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
