#include <bits/stdc++.h>
using namespace std;

int lisNLogN(vector<int> &nums)
{
    vector<int> subsequences;
    subsequences.emplace_back(nums[0]);
    for (int ii = 1; long(ii) < nums.size(); ii++)
    {
        int i = nums[ii];
        if (i > subsequences.back())
        {
            subsequences.emplace_back(i);
        }
        else
        {
            auto it = lower_bound(subsequences.begin(), subsequences.end(), i);
            *it = i;
        }
    }
    // for (int i = 0; i < subsequences.size(); i++)
    // {
    //     cout<<subsequences[i]<<" \n"[i==subsequences.size()-1];
    // }

    return subsequences.size();
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

    int n;
    cin >> n;
    vector<int> subsequences;
    bool f = 0;
    while (n--)
    {
        int i;
        cin >> i;
        if (!f)
        {
            subsequences.emplace_back(i);
            f = 1;
        }
        else
        {
            if (i > subsequences.back())
            {
                subsequences.emplace_back(i);
            }
            else
            {
                auto it = lower_bound(subsequences.begin(), subsequences.end(), i);
                *it = i;
            }
        }
    }
    cout << subsequences.size() << endl;
}