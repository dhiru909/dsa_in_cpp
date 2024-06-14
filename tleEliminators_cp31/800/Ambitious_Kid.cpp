#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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
    t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            mini = min(mini, abs(temp - 0));
        }
        cout << mini << endl;
    }
}