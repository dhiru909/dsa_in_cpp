#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class SegmentTree
{
public:
    ll *seg;
    SegmentTree(int n, ll arr[])
    {
        seg = new long long[n * 4 + 1];
        build(1, n, 1, arr);
    }
    void build(int l, int r, int ind, ll arr[])
    {
        if (l == r)
        {
            seg[ind] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(l, mid, ind * 2, arr);
        build(mid + 1, r, ind * 2 + 1, arr);
        seg[ind] = seg[ind * 2] + seg[ind * 2 + 1];
        return;
    }
    ll query(int l, int r, int qs, int qe, int ind)
    {
        if (qs > r or qe < l)
            return 0;
        else if (qs <= l and qe >= r)
            return seg[ind];
        int mid = l + (r - l) / 2;
        ll left = query(l, mid, qs, qe, ind * 2);
        ll right = query(mid + 1, r, qs, qe, ind * 2 + 1);
        return left + right;
    }
    void update(int l, int r, int ind, int indexToUpdate, int value)
    {
        if (l == r)
        {
            seg[ind] = value;
            return;
        }
        int mid = l + (r - l) / 2;
        if (indexToUpdate <= mid)
            update(l, mid, ind * 2, indexToUpdate, value);
        else
            update(mid + 1, r, ind * 2 + 1, indexToUpdate, value);
        seg[ind] = seg[ind * 2] + seg[ind * 2 + 1];
    }
};
int main()
{
    // cout<<"hello\n";
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    ll arr[n + 1];  
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    SegmentTree tree(n, arr);
    // cout<<"sgdggd";
    vector<ll>res;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll idx, val;
            cin >> idx >> val;
            // Add the value to the element at index 'idx' in the array.
            tree.update(1, n, 1, idx, val);
        }
        else
        {
            ll L, R;
            cin >> L >> R;
            ll ans =  tree.query(1, n, L, R, 1);
            res.emplace_back(ans);
        }
    }
    for(auto &i:res){
        cout<<i<<"\n";
    }
}