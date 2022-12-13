#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool canJump(int i, vector<int> v, vector<int> &dp)
{
    if (dp[i] != -1)
    {
        return dp[i];
    }
    if (i == 0)
    {
        dp[i] = 1;
        return true;
    }
    if (v[i] == 0 && i != v.size() - 1)
    {
        dp[i] = 0;
        return dp[i];
    }
    int jm = v[i];
    bool f = false;
    for (int j = jm; j >= 1; j--)
    {
        f = f || canJump(i + j, v, dp);
    }
    dp[i] = f;
    return dp[i];
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
    int n;
    cin >> n;
    vector<int> jump;
    vector<int> dp(n + 1, -1);
    jump.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        jump.push_back(x);
    }
    cout << canJump(n - 1, jump, dp);
    cout << "\n";
    for (int i : dp)
        cout << i << " ";
    return 0;
}