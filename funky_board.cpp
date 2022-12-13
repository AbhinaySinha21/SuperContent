#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int c = 0;
bool issafe(vector<vector<int>> v, int i, int j)
{
    if (i < 0 || j < 0 || j >= v[0].size() || i >= v.size() || v[i][j] == 0 || v[i][j] == -1)
        return false;
    return true;
}
void funky_path(vector<vector<int>> v, int i, int j, int c_k)
{
    if (c_k >= c)
        c = c_k;
    vector<int> row = {-1, -2, 2, 1, -1, -2, 2, 1};
    vector<int> col = {-2, -1, 1, 2, 2, 1, -1, -2};
    for (int k = 0; k < 8; k++)
    {
        if (issafe(v, i, j))
        {
            v[i][j] = -1;
            funky_path(v, i + row[k], j + col[k], c_k + 1);
            v[i][j] = 1;
        }
    }
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
    vector<vector<int>> v;
    int o = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> dem;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
                o++;
            dem.push_back(x);
        }
        v.push_back(dem);
    }
    funky_path(v, 0, 0, 0);
    cout << o - c;
    return 0;
}