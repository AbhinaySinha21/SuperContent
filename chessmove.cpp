#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int c = 0;
vector<string> all;
void chessmoves(int i, int j, int n, int m, string ans)
{
    if (i == n - 1 && j == m - 1)
    {
        c++;
        all.push_back(ans);
        return;
    }
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;

    chessmoves(i + 2, j + 1, n, m, ans + 'K' + '{' + to_string(i + 2) + '-' + to_string(j + 1) + '}');
    chessmoves(i + 1, j + 2, n, m, ans + 'K' + '{' + to_string(i + 1) + '-' + to_string(j + 2) + '}');
    if (i == n - 1 || i == 0 || j == m - 1 || j == 0)
    {
        for (int c = 1; c < m; c++)
            chessmoves(i, j + c, n, m, ans + 'R' + '{' + to_string(i) + '-' + to_string(j + c) + '}');
        for (int r = 1; r < n; r++)
            chessmoves(i + r, j, n, m, ans + 'R' + '{' + to_string(i + r) + '-' + to_string(j) + '}');
    }
    if (i == 0 && j == 0 || (i > 0 && j > 0))
    {
        for (int k = 1; k < n; k++)
            chessmoves(i + k, j + k, n, m, ans + 'B' + '{' + to_string(i + k) + '-' + to_string(j + k) + '}');
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
    chessmoves(0, 0, n, n, "{0-0}");
    string s = "{0-0}K{2-1}R{2-2} {0-0}K{1-2}R{2-2} {0-0}R{0-1}K{2-2} {0-0}R{0-1}R{0-2}R{1-2}R{2-2} {0-0}R{0-1}R{0-2}R{2-2} {0-0}R{0-1}R{1-1}B{2-2} {0-0}R{0-1}R{2-1}R{2-2} {0-0}R{0-2}R{1-2}R{2-2} {0-0}R{0-2}R{2-2} {0-0}R{1-0}K{2-2} {0-0}R{1-0}R{1-1}B{2-2} {0-0}R{1-0}R{1-2}R{2-2} {0-0}R{1-0}R{2-0}R{2-1}R{2-2} {0-0}R{1-0}R{2-0}R{2-2} {0-0}R{2-0}R{2-1}R{2-2} {0-0}R{2-0}R{2-2} {0-0}B{1-1}B{2-2} {0-0}B{2-2} ";
    vector<string> allone;
    string demo = "";
    map<string, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            allone.push_back(demo);
            demo = "";
        }
        else
            demo += s[i];
    }
    cout << allone.size() << " " << all.size() << "\n";
    for (int i = 0; i < all.size(); i++)
        cout << allone[i] << "\t" << all[i] << "\n";
    return 0;
}