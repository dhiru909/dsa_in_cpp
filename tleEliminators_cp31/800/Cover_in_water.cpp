#include <bits/stdc++.h>
using namespace std;

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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ctOfBlockedCells = 0;
        int countOfContiguousEmptyCells = 0;
        bool isThereAny3EmptyConnected = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '.')
            {
                countOfContiguousEmptyCells++;
            }
            if (countOfContiguousEmptyCells > 2)
            {
                isThereAny3EmptyConnected = true;
                break;
            }
            if (s[i] == '#')
            {
                countOfContiguousEmptyCells = 0;
                ctOfBlockedCells++;
            }
        }
        if (isThereAny3EmptyConnected)
        {
            cout << 2 << '\n';
        }
        else
        {
            cout << n - ctOfBlockedCells << '\n';
        }
    }
}