#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool ispossible(vector<int> v, int c, int mid)
{
    int cow = 1;
    int pos = v[0];
    int i = 1;
    for (; i < v.size(); i++)
    {
        if (v[i] - pos >= mid)
        {
            cow++;
            pos = v[i];
        }
        if (cow >= c)
            return true;
    }
    return false;
}
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
        int n, c;
        cin >> n >> c;
        vector<int> v;
        v.reserve(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int st = 0;
        int ed = v[v.size() - 1] - v[0];
        int ans, mid;
        while (st <= ed)
        {
            if (ispossible(v, c, mid))
            {
                ans = mid;
                st = mid + 1;
            }
            else
                ed = mid - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}