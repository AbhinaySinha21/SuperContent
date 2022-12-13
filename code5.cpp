#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int c = 0;
bool issafe(vector<vector<int>> v, int row, int col)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
            if (v[i][j] == 1)
            {
                if (row == i || col == j || abs(row - i) == abs(col - j))
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
                cout << "{" << (i + 1) << "-" << (j + 1) << "} ";
    }
    cout << " ";
}
void Nqueen(vector<vector<int>> &v, int nq, int row)
{
    if (nq == 0)
    {
        c++;
        return;
    }
    for (int col = 0; col < v[0].size(); col++)
    {
        if (issafe(v, row, col))
        {
            v[row][col] = 1;
            Nqueen(v, nq - 1, row + 1);
            v[row][col] = 0;
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
    vector<vector<int>> board;
    for (int i = 0; i < n; i++)
    {
        vector<int> h(n, 0);
        board.push_back(h);
    }
    Nqueen(board, n, 0);
    cout << c;
    return 0;
}