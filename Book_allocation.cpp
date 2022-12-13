#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool ispossible(vector<int> pages, int m, int mid)
{
    int nc = 1;
    int sum = 0;
    for (int i = 0; i < pages.size(); i++)
    {
        if (sum + pages[i] <= mid)
        {
            sum += pages[i];
        }
        else
        {
            sum = pages[i];
            nc++;
            if (nc > m || sum > mid)
            {
                return false;
            }
        }
    }

    return true;
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
        int n, m, tn = 0;
        cin >> n >> m;
        vector<int> pages;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            tn += x;
            pages.push_back(x);
        }
        int st, ed, mid;
        st = 1;
        ed = tn;
        int ans;
        while (st <= ed)
        {
            mid = (ed + st) / 2;
            if (ispossible(pages, m, mid))
            {
                ans = mid;
                ed = mid - 1;
            }
            else
                st = mid + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}