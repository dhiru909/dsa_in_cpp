#include <bits/stdc++.h>
using namespace std;
const int maxN = 1001;

char c;
int N, Q, a[maxN][maxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
    freopen("errorf.err", "w", stderr);
#endif
    memset(a, 0, sizeof(a));
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf(" %c", &c);
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            if (c == '*')
                a[i][j]++;
        }
    }
    while (Q--)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1]);
    }
}