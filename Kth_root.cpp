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
        ll n, p;
        cin >> n >> p;
        ll st = 1;
        ll ed = n;
        ll mid;
        if (p == 1)
            cout << n << "\n";
        else
        {
            ll ans = 0;
            while (st <= ed)
            {
                mid = (ed + st) / 2;
                if (n == pow(mid, p))
                {
                    ans = mid;
                    break;
                }
                else if (n > pow(mid, p))
                {
                    if (n < pow(mid + 1, p))
                    {
                        ans = mid;
                        break;
                    }
                    else
                    {
                        st = mid + 1;
                    }
                }
                else
                    ed = mid - 1;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}