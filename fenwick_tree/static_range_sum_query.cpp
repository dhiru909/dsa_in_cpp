#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void update(ll arr[], int n, int ind, int val)
{
    for (int i = ind; i <= n; i += (i & -i))
    {
        arr[i] += val;
    }
}
long long query(ll arr[], int n, int ind)
{
    long long sum = 0;
    for (int i = ind; i >0; i -= (i & -i))
    {
        sum += arr[i];
    }
    return sum;
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

    int n, q;
    cin >> n >> q;
    ll arr[n + 1] = {0};
    for (int i = 1; i < n + 1; i++)
    {
        ll t;
        cin >> t;
        update(arr, n, i, t);
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << query(arr, n, b) - query(arr, n, a - 1) << '\n';
    }
}