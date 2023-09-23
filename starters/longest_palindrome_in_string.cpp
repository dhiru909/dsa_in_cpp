//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string longestPalin(string S)
    {
        // code here
        // odd length
        int n = S.size();
        int maxlen = 1;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            int l = i, h = i;
            while (S[l] == S[h])
            {
                if (h - l + 1 > maxlen)
                {
                    start = l;
                    maxlen = h - l + 1;
                }
                l--;
                h++;
                if (l < 0 && h >= n)
                    break;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            int l = i, h = i + 1;
            while (S[l] == S[h])
            {
                if (h - l + 1 > maxlen)
                {
                    start = l;
                    maxlen = h - l + 1;
                }
                l--;
                h++;
                if (l < 0 && h >= n)
                    break;
            }
        }
        // cout<<start<<" "<<maxlen;
        return S.substr(start, maxlen);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalin(S) << endl;
    }
}