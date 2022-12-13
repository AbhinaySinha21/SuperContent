#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> visit;
void display2(vector<vector<int>> visit)
{
    for (auto it : visit)
    {
        for (int ch : it)
            cout << ch << " ";
        cout << "\n";
    }
}
bool f = false;
void rattocheese(vector<vector<char>> v, int i, int j, int n, int m)
{
    if (i == n - 1 && j == m - 1 && v[i][j] != 'X')
    {
        f = true;
        visit[i][j] = 1;
        display2(visit);
        cout << "\n";
        return;
    }
    if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || v[i][j] == 'X')
        return;
    visit[i][j] = 1;
    vector<int> row = {1, 0};
    vector<int> col = {0, 1};
    for (int k = 0; k < 2; k++)
        rattocheese(v, i + row[k], j + col[k], n, m);
    visit[i][j] = 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<char>> v;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<char> dem;
        vector<int> demo(m, 0);
        visit.push_back(demo);
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            dem.push_back(ch);
        }
        v.push_back(dem);
    }
    rattocheese(v, 0, 0, n, m);
    if (!f)
        cout << "-1";
    return 0;
}