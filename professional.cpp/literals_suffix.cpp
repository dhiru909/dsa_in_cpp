#include <bits/stdc++.h>
using namespace std;
int main()
{
    float aa = 23;
    // auto s=[](int i){

    // decltype(a) y=23.56;
    // cout<<i<<" "<<y;
    // };
    // s(3);
    vector<int> a = {1, 2, 3, 4, 8};
    auto m = accumulate(a.begin(), a.end(), 1, [=](int i, int j)
                        {cout<<i<<" "<<j<<endl;return j%2==0?aa*j:i*1; });
    cout << m;
}