#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a, b;
        a.reserve(n);
        b.reserve(m);
        int i = 0, j = 0;
        int r = 0, sum1 = 0, sum2 = 0;
        while (i < m && j < n)
        {
            if (a[i] < b[j])
            {
                sum1 += a[i];
                i++;
            }
            else if (a[i] > b[j])
            {
                sum2 += b[j];
                j++;
            }
            else
            {
                r += max(sum1, sum2) + a[i];
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }
        while (i < m)
        {
            sum1 += a[i];
            i++;
        }
        while (j < n)
        {
            sum2 += b[j];
            j++;
        }
        r += max(sum1, sum2);
    }
    return 0;
}