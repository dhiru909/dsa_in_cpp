#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 200005;
const int LOG = 17;
int a[MAX_N];
int minimumSparse[MAX_N][LOG];
int bin_log[MAX_N];
int query(int a, int b)
{
    int lg = bin_log[b - a + 1];
    return min(minimumSparse[a][lg], minimumSparse[b - (1 << lg) + 1][lg]);
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
    // ?   1.. Take INPUT
    cin >> n >> q;
    bin_log[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        bin_log[i] = bin_log[i / 2] + 1;
    }
    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
        minimumSparse[i][0] = a[i];
    }

    // ?  2.. Preprocessing
    for (int j = 1; j <= LOG; j++)
    {
        for (int i = 0; i - 1 + (1 << j) < n; i++)
        {
            minimumSparse[i][j] = min(minimumSparse[i][j - 1], minimumSparse[i + (1 << (j - 1))][j - 1]);
        }
    }

    // ?  3.. QUERIES
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        cout << query(a, b) << '\n';
    }
}