#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
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
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 > y2)
        {

            cout << "-1" << endl;
        }
        else if (x2 - (y2 - y1) > x1)
        {

            cout << "-1" << endl;
        }
        else
        {
            cout << x1 - (x2 - (y2 - y1)) + y2 - y1 << endl;
        }
    }
}