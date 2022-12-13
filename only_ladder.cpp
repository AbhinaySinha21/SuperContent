#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define N 1e6 - 1
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
                return Qprime.size() - i - 1 > i ? Qprime.size() - i - 1 : -1;
    }
    return -1;
}
void createprimeArray(int n)
{
    for (int i = 0; i <= n; i++)
        if (sieve[i])
            Qprime.push_back(i);
}
void ladder(int n, int i, string s)
{
    if (n == i)
    {
        cout << s << "\n";
        return;
    }
    if (n < i)
        return;
    int p = primelad(i);
    if (p != -1)
    {
        if (Qprime[p] == n)
            ladder(n, Qprime[p], s + "END");
        else
            ladder(n, Qprime[p], s + to_string(Qprime[p]) + " ");
    }
    for (int k = 1; k <= 6; k++)
        if (k <= n)
        {
            if (i + k == n)
                ladder(n, i + k, s + "END");
            else
                ladder(n, i + k, s + to_string(i + k) + " ");
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
    createprimeArray(n);
    ladder(n, 0, "0 ");
    return 0;
}