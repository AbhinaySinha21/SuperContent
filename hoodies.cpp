#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q;
    cin >> q;
    vector<ll> v(5, -1);
    v[0] = 0;
    queue<ll> qe[5];

    while (q--)
    {
        char ch;
        cin >> ch;
        if (ch == 'E')
        {
            ll x, y;
            cin >> x >> y;
            v[0]++;
            qe[x].push(y);
            if (v[x] == -1)
                v[x] = v[0];
        }
        else
        {
            ll i = 0;
            ll minL = INT_MAX;
            for (ll k = 1; k <= 4; k++)
                if (v[k] != -1 && v[k] < minL)
                {
                    minL = v[k];
                    i = k;
                }

            cout << i << " " << qe[i].front() << "\n";

            qe[i].pop();
            if (qe[i].empty())
                v[i] = -1;
        }
    }
}