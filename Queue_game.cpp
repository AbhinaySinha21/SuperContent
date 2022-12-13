#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        v.reserve(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        int c = 0;
        bool f = true;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 1)
                c++;
            else
                c--;
            if (c < 0)
            {
                f = false;
                break;
            }
        }
        if (f)
            cout << "Valid\n";
        else
            cout << "Invalid\n";
    }
    return 0;
}