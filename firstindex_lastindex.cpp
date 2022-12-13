#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int search(vector<int> v, int tar, bool index1)
{
    int st = 0;
    int ed = v.size() - 1;
    int mid, ans = -1;
    while (st <= ed)
    {
        mid = (ed + st) / 2;
        if (v[mid] > tar)
            ed = mid - 1;
        else if (v[mid] < tar)
            st = mid + 1;
        else
        {
            if (index1)
            {
                if (mid == 0)
                {
                    ans = mid;
                    break;
                }
                else if (v[mid - 1] != tar)
                {
                    ans = mid;
                    break;
                }
                else
                    ed = mid - 1;
            }
            else
            {
                if (mid == v.size() - 1)
                {
                    ans = mid;
                    break;
                }
                else if (v[mid + 1] != tar)
                {
                    ans = mid;
                    break;
                }
                else
                    st = mid + 1;
            }
        }
    }
    return ans;
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
    vector<int> v = {6, 7, 7, 7, 9};
    int first = search(v, 7, true);
    int second = search(v, 7, false);
    cout << first << " " << second;
    return 0;
}