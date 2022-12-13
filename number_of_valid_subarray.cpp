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
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[i] < v[st.top()])
            st.pop();
        st.push(i);
        ans += st.size();
    }
    cout << ans << "\n";
    return 0;
}