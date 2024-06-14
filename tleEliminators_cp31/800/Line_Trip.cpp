#include <bits/stdc++.h>
using namespace std;
int arr[53];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
    freopen("errorf.err", "w", stderr);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        arr[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        arr[n + 1] = x + (x - arr[n]);
        int ans = -1;
        for (int i = 1; i <= n + 1; i++)
        {
            ans = max(ans, arr[i] - arr[i - 1]);
        }
        cout << ans << '\n';
    }
}