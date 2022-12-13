#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int c = 0;
set<string> s;
bool issafe(vector<vector<int>> v, int row, int col)
{
    vector<int> Arow = {-1, -2, -2, -1};
    vector<int> Acol = {-2, -1, 1, 2};
    for (int i = 0; i < Arow.size(); i++)
    {
        if (v[row][col] == 1)
            return false;
        if (row + Arow[i] >= 0 && (col + Acol[i] >= 0 || col + Acol[i] < v.size()))
        {
            if (v[row + Arow[i]][col + Acol[i]] == 1)
                return false;
        }
    }
    return true;
}
void Display(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
            if (v[i][j] == 1)
                cout << ("{" + to_string(i) + "-" + to_string(j) + "} ");
    }
    cout << " ";
}
void display(vector<vector<int>> v)
{
    for (auto it : v)
    {
        for (int i : it)
            cout << i << " ";
        cout << "\n";
    }
}
void NKnight(vector<vector<int>> &v, int nk, int row, int col)
{
    if (nk == 0)
    {
        c++;
        Display(v);
        cout << "\n";
        return;
    }
    if (col == v.size())
    {
        NKnight(v, nk, row + 1, 0);
    }
    if (row < 0 || col < 0 || row >= v.size() || col >= v[0].size())
        return;
    if (issafe(v, row, col))
    {
        v[row][col] = 1;
        NKnight(v, nk - 1, row, col + 1);
        v[row][col] = 0;
    }
    NKnight(v, nk, row, col + 1);
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
    vector<vector<int>> board;
    for (int i = 0; i < n; i++)
    {
        vector<int> h(n, 0);
        board.push_back(h);
    }
    NKnight(board, n, 0, 0);
    cout << "\n"
         << c;
    return 0;
}