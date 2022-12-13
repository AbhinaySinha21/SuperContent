#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int HistoArea(vector<int> v)
{
    stack<int> st;
    int maxA = 0;
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[i] < v[st.top()])
        {
            int p = st.top();
            int h = v[p];
            st.pop();
            int r = i;
            if (st.empty())
            {
                maxA = max(maxA, h * r);
            }
            else
            {
                int l = st.top();
                maxA = max(maxA, h * (r - l - 1));
            }
        }
        st.push(i);
    }
    int r = v.size();
    while (!st.empty())
    {
        int p = st.top();
        int h = v[p];
        st.pop();
        if (st.empty())
        {
            maxA = max(maxA, h * r);
        }
        else
        {
            int l = st.top();
            maxA = max(maxA, h * (r - l - 1));
        }
    }
    return maxA;
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
    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << HistoArea(v);
    return 0;
}