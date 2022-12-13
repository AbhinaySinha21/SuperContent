#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool ispossible(vector<int> v, int p, int mid)
{
    int time, c = 0, r;
    for (int i = 0; i < v.size(); i++)
    {
        time = 0;
        r = 1;
        while (true)
        {
            if (time + v[i] * r <= mid)
            {
                time += v[i] * r;
                c++;
                r++;
            }
            else
                break;
        }
        if (c >= p)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int p;
    cin >> p;
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
    int st = 0;
    int ed = 1e8;
    int mid, ans;
    while (st <= ed)
    {
        mid = (ed + st) / 2;
        if (ispossible(v, p, mid))
        {
            ans = mid;
            ed = mid - 1;
        }
        else
            st = mid + 1;
    }
    cout << ans << "\n";
    return 0;
}