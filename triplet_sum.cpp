#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int target;
    cin >> target;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (i > 0 && v[i] == v[i - 1])
            continue;
        int l = i + 1;
        int r = v.size() - 1;
        int tar = target - v[i];
        while (l < r)
        {
            if (v[l] + v[r] == tar)
            {
                cout << v[i] << ", " << v[l] << " and " << v[r] << "\n";
                while (l < v.size() - 1 && v[l] == v[l + 1])
                    l++;
                while (r > 0 && v[r] == v[r - 1])
                    r--;
                l++;
                r--;
            }
            else if (v[l] + v[r] > tar)
                r--;
            else if (v[l] + v[r] < tar)
                l++;
        }
    }
    return 0;
}