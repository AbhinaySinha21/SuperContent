#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define N 1e8 - 1
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
    int c = 0;
    for (int i = 0;; i++)
    {
        if (sieve[i] == true)
        {
            c++;
            Qprime.push_back(i);
        }
        if (c == 1e5)
            break;
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
    createSieve();
    int n, q;
    cin >> n >> q;
    stack<ll> st;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        st.push(x);
    }
    int k = 1;
    vector<int> ans;
    while (k <= q)
    {
        stack<ll> A, B;
        while (!st.empty())
        {
            if (st.top() % Qprime[k - 1] == 0)
                B.push(st.top());
            else
                A.push(st.top());
            st.pop();
        }
        while (!B.empty())
        {
            ans.push_back(B.top());
            B.pop();
        }
        k++;
        st = A;
        if (k > q)
            break;
    }
    for (int i : ans)
        cout << i << "\n";
    while (!st.empty())
    {
        cout << st.top() << "\n";
        st.pop();
    }
    return 0;
}