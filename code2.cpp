#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void displayV(vector<int> v)
{
    for (int i : v)
        cout << i << " ";
    cout << "|";
}
int sum(vector<int> v)
{
    int s = 0;
    for (int i : v)
        s += i;
    return s;
}
int sumofparts(vector<int> v, int i, int j, double sum)
{
    if (i == j)
        return 0;
    long demos = 0;
    int dem = 0;
    for (int k = i; k <= j; k++)
    {
        demos += v[k];
        if (demos >= sum / 2)
        {
            dem = k;
            break;
        }
    }
    if (demos != sum / 2)
        return 0;
    int maxL = sumofparts(v, i, dem, demos) + 1;
    int maxR = sumofparts(v, dem + 1, j, demos) + 1;
    return max(maxL, maxR);
}
vector<vector<int>> visit;
bool flag = false;
void display2(vector<vector<int>> visit)
{
    for (auto it : visit)
    {
        for (bool ch : it)
            cout << ch << " ";
        cout << "\n";
    }
}
void rattocheese(vector<vector<char>> v, int i, int j, int n, int m)
{
    if (i == n - 1 && j == m - 1 && v[i][j] != 'X')
    {
        flag = true;
        visit[i][j] = 1;
        display2(visit);
        return;
    }
    if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || v[i][j] == 'X')
        return;
    v[i][j] = 'X';
    visit[i][j] = 1;
    vector<int> row = {1, 0, -1, 0};
    vector<int> col = {0, 1, 0, -1};
    for (int k = 0; k < row.size(); k++)
        rattocheese(v, i + row[k], j + col[k], n, m);
    visit[i][j] = 0;
    v[i][j] = 'O';
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
    if (!flag)
        cout << "NO PATH FOUND\n";
    return 0;
}