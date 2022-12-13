#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void insert(stack<int> &st, int it)
{
    if (st.empty())
    {
        st.push(it);
        return;
    }
    for (int i = 0; i < st.size(); i++)
    {
        int ele = st.top();
        st.pop();
        insert(st, ele);
        st.push(ele);
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
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    insert(st, -3);
    return 0;
}