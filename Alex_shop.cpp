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
    int q;
    cin >> q;
    while (q--)
    {
        int A, k;
        cin >> A >> k;
        int c = 0;
        for (int i = 0; i < n; i++)
            if (A % v[i] == 0)
                c++;
        if (c == k)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}