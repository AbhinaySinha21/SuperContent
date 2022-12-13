#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool f = true;
vector<vector<int>> visit;
void display(vector<vector<int>> v)
{
    for (auto it : v)
    {
        for (int i : it)
            cout << i << " ";
        cout << "\n";
    }
}
void ratright(vector<vector<char>> v, int i, int j, int n, int m)
{
    if (i == n - 1 && j == m - 1 && v[i][j] != 'X' && f)
    {
        visit[i][j] = 1;
        f = false;
        display(visit);
        return;
    }
    if (i < 0 || j < 0 || j >= m || i >= n || v[i][j] == 'X')
        return;
    v[i][j] = 'X';
    visit[i][j] = 1;
    ratright(v, i, j + 1, n, m);
    ratright(v, i + 1, j, n, m);
    v[i][j] = 'O';
    visit[i][j] = 0;
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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v;
    for (int i = 0; i < n; i++)
    {
        vector<char> dem;
        vector<int> demo(m, 0);
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            dem.push_back(ch);
        }
        v.push_back(dem);
        visit.push_back(demo);
    }
    ratright(v, 0, 0, n, m);
    if (f)
        cout << "-1";
    return 0;
}