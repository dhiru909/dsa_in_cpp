#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int> &a,int n,int i){
    int largest = i;
    int left=i*2+1;
    int right=i*2+2;
    if(left<(n) && a[left]>a[largest]){
        largest = left;
    }
    if(right<(n) && a[right]>a[largest]){
        largest = right;
    }
    if(largest!=i){
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}
void heap_sort(vector<int> &a){
    heap_build(a);
    for(int i= a.size()-1; i>=0;i--){
        swap(a[i],a[0]);
        heapify(a,i ,0);
    }
}
void heap_build(vector<int> &a){
    for(int i=(a.size())/2;i>=0;i--){
        heapify(a,a.size(),i);
    }
}
int main(){
    vector<int> a={10,30,50,20,35,15};
    
    heap_sort(a);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}