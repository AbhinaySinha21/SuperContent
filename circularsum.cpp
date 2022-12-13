#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum = 0;
        cin >> n;
        vector<int> v;
        v.reserve(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            sum += x;
            v.push_back(x);
        }
        int sumR, sumL, maxR, maxL;
        sumR = sumL = maxR = maxL = v[0];
        for (int i = 1; i < n; i++)
        {
            {
                sumL = max(sumL + v[i], v[i]);
                maxL = max(maxL, sumL);
            }
        }
        for (int i = 1; i < n; i++)
        {
            sumR = min(sumR + v[i], v[i]);
            maxR = min(maxR, sumR);
        }
        cout << max(maxL, sum - maxR) << "\n";
    }
    return 0;
}