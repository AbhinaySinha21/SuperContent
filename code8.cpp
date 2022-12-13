#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int oddMax(map<string, int> m)
{
    int maxL = 0;
    for (auto it : m)
        if (it.second % 2 != 0)
            if (maxL <= it.second)
                maxL = it.second;
    return maxL;
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
    //     vector<int> v = {2, 8, 9, 4, 3, 1, 10};
    //     int p = 4;
    //     int st = 0;
    //     int ed = v.size() - 1;
    //     while (st < ed)
    //     {
    //         while (v[st] < p)
    //             st++;
    //         while (v[ed] > p)
    //             ed--;
    //         if (st < ed)
    //         {
    //             int tem = v[st];
    //             v[st] = v[ed];
    //             v[ed] = tem;
    //             st++;
    //             ed--;
    //         }
    //     }
    //     for (int i : v)
    //         cout << i << " ";
    // vector<string> v = {"cl", "gg", "lc"};
    // for (int i = 0; i < v.size(); i++)
    // {
    //     vector<string> ni = concatV(v, 0, i, {});
    //     vector<string> ne = concatV(v, i + 1, v.size(), ni);
    //     for (string s : ne)
    //         cout << s << " ";
    //     cout << "\n";
    // }
    vector<string> v = {"dd", "aa", "bb", "dd", "aa", "dd", "bb", "dd", "aa", "cc", "bb", "cc", "dd", "cc"};
    map<string, int> m;
    int c = 0;
    for (string s : v)
        m[s]++;
    int maxL = oddMax(m);
    for (auto it : m)
    {
        cout << it.first << " " << it.second << "\n";
        string dem = it.first;
        char temp = dem[0];
        dem[0] = dem[1];
        dem[1] = temp;
        if (it.first[0] == it.first[1])
        {
            if (it.second == maxL)
            {
                c += (2 * it.second);
                maxL = 0;
            }
            else if (it.second % 2 == 0)
                c += (2 * it.second);
            else if (it.second % 2 != 0)
                c += (2 * (it.second - it.second % 2));
        }
        else if (m.find(dem) != m.end())
        {
            c += (2 * min(m[dem], m[it.first]));
        }
        cout << c << "\n";
    }
    return 0;
}
