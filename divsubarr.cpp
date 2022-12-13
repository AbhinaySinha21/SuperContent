#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> v;
    v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 0;
    int j = 0;
    int c = 1;
    int n1, n;
    n1 = n = v.size();
    int i;
    while (k < n1 && j < n)
    {
        for (i = j; i < n; ++i)
        {
            cout << v[k][i] << " ";
        }
        k++;
        for (i = k; i < n1; ++i)
        {
            cout << v[i][n - 1] << " ";
        }
        n--;
        if (k < n1)
        {
            for (i = n - 1; i >= j; --i)
            {
                cout << v[n1 - 1][i] << " ";
            }
            n1--;
        }
        if (j < n)
        {
            for (i = n1 - 1; i >= k; --i)
            {
                cout << v[i][j] << " ";
            }
            j++;
        }
    }
    return 0;
}