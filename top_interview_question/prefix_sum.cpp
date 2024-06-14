#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = 0;
    int ans = 0;
    while (l < n)
    {
        if (arr[l] == 1)
        {
            int r = l;
            while (arr[r] == 1)
                r++;
            ans = max(ans, r - l);
            l = r;
        }
        else
        {
            l++;
        }
    }
    cout << ans << '\n';
}