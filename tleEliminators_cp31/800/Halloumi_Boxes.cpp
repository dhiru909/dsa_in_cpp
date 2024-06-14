#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef LOCAL
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
    freopen("errorf.err", "w", stderr);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int temp = -1;
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            int curr;
            cin >> curr;
            if (curr < temp)
                flag = 1;
            temp = curr;
        }
        if (k == 1)
        {
            if (!flag)
                printf("YES\n");
            else
            {
                printf("NO\n");
            }
        }
        else
            printf("YES\n");
    }
}