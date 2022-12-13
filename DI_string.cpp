#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string pattern = "DDIIDI";
    stack<int> st;
    vector<int> ans;
    ans.reserve(pattern.length() + 1);
    int m = 1;
    for (int i = 0; i <= pattern.length(); i++)
    {
        if (pattern[i] == 'D')
            st.push(i);
        else if (pattern[i] == 'I' || i == pattern.length())
        {
            ans[i] = m;
            while (!st.empty())
            {
                m++;
                int p = st.top();
                ans[p] = m;
                st.pop();
            }
        }
    }
    for (int i : ans)
        cout << i << " ";
    return 0;
}