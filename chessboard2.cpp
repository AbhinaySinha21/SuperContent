#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define N 1e8 - 1
int c = 0;
vector<string> all;
vector<bool> sieve(N + 1, false);
vector<int> Qprime;
void createSieve()
{
    for (int i = 2; i <= N; i++)
        sieve[i] = true;
    for (int i = 2; i * i < N; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
                sieve[j] = false;
        }
    }
}
int primelad(int n)
{
    if (sieve[n])
    {
        for (int i = 0; i < Qprime.size(); i++)
            if (Qprime[i] == n)
                return i;
    }
    return -1;
}
void createprimeArray(int n)
{
    for (int i = 0; i <= n; i++)
        if (sieve[i])
            Qprime.push_back(i);
}
void chessprime(int i, int j, int n, int m, string ans)
{
    if (i == n - 1 && j == m - 1)
    {
        c++;
        all.push_back(ans);
        return;
    }
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;
    int p = primelad(i * n + j + 1);
    if (p != -1)
    {
        if (p % 2 != 0)
            chessprime(n - 1, n - 1, n, n, ans + 'P' + '{' + to_string(n - 1) + '-' + to_string(n - 1) + '}');
        else
            return;
    }
    chessprime(i + 2, j + 1, n, m, ans + 'K' + '{' + to_string(i + 2) + '-' + to_string(j + 1) + '}');
    chessprime(i + 1, j + 2, n, m, ans + 'K' + '{' + to_string(i + 1) + '-' + to_string(j + 2) + '}');
    if (i == n - 1 || i == 0 || j == m - 1 || j == 0)
    {
        for (int c = 1; c < m; c++)
            chessprime(i, j + c, n, m, ans + 'R' + '{' + to_string(i) + '-' + to_string(j + c) + '}');
        for (int r = 1; r < n; r++)
            chessprime(i + r, j, n, m, ans + 'R' + '{' + to_string(i + r) + '-' + to_string(j) + '}');
    }
    if (i == 0 && j == 0 || (i > 0 && j > 0))
    {
        for (int k = 1; k < n; k++)
            chessprime(i + k, j + k, n, m, ans + 'B' + '{' + to_string(i + k) + '-' + to_string(j + k) + '}');
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
    createSieve();
    createprimeArray(n * n);
    chessprime(0, 0, n, n, "{0,0}");
    for (string s : all)
        cout << s << "\n";
    cout << c;
    return 0;
}