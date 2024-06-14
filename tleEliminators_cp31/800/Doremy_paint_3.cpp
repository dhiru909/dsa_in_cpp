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
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            mp[temp]++;
        }
        if (mp.size() > 2)
            cout << "No" << endl;
        else if (mp.size() == 1)
            cout << "Yes" << endl;
        else
        {
            auto iter = mp.begin();
            int a = iter->second;
            iter++;
            int b = (iter)->second;
            if (abs(a - b) > 1)
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }
    }
}