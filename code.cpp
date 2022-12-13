#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
static int c = 0;
void Printanswer(vector<bool> board, int tq, int qpsf, string ans)
{
    if (qpsf == tq)
    {
        cout << ans << "\n";
        return;
    }
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i] == false)
        {
            board[i] = true;
            Printanswer(board, tq, qpsf + 1, ans + "b" + to_string(i) + "q" + to_string(qpsf));
            // board[i] = false; comment it for combination
        }
    }
}

bool search(string s, char ch)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (ch == s[i])
            return false;
    }
    return true;
}
void towerofhanoi(int n, char st, char hel, char des)
{
    if (n == 0)
        return;
    towerofhanoi(n - 1, st, des, hel);
    cout << st << "->" << des << "\n";
    towerofhanoi(n - 1, hel, st, des);
}
void Lexiocounting(int curr, int n)
{
    if (curr > n)
        return;
    cout << curr << "\n";
    int i = 0;
    if (curr == 0)
        i = 1;
    for (; i < 9; i++)
    {
        Lexiocounting(curr * 10 + i, n);
    }
}
void permutation(string s, string demo, int n)
{
    if (n == demo.length())
    {
        cout << demo << "\n";
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        string tough = s.substr(0, i) + s.substr(i + 1, s.length() - (i + 1));
        if (search(s.substr(i + 1, s.length() - (i + 1)), s[i]))
            permutation(tough, demo + s[i], n);
    }
}
bool ispalin(string s)
{
    int i = 0;
    int j = s.length() - 1;
    for (; i < j; i++, j--)
        if (s[i] != s[j])
            return false;
    return true;
}
void sumofterms(int sum, vector<int> v, vector<int> ans)
{
    if (sum == 0)
    {
        for (int i : ans)
            cout << i << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (sum >= v[i] && find(ans.begin(), ans.end(), v[i]) == ans.end())
        {
            ans.push_back(v[i]);
            sumofterms(sum - v[i], v, ans);
            ans.pop_back();
        }
    }
}
vector<vector<string>> ansv;
void stringPart(string q, vector<string> v)
{
    if (q.length() == 0)
    {
        ansv.push_back(v);
        return;
    }
    for (int i = 1; i <= q.length(); i++)
    {
        string s = q.substr(0, i);
        if (ispalin(s))
        {
            v.push_back(s);
            stringPart(q.substr(i), v);
            v.erase(v.end() - 1);
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
    // reach_the_destination(10, "", 10);
    // permutation(s, "", s.length());
    // towerofhanoi(3, 'A', 'B', 'C');
    // int tq = 2;
    // int n = 4;
    // vector<bool> v(n, false);
    // Printanswer(v, tq, 0, "");
    int sum;
    cin >> sum;
    sumofterms(sum, {10, 1, 2, 7, 6, 1, 5}, {});
    // stringPart("aab", {});
    // for (vector<string> dem : ansv)
    // {
    //     for (string h : dem)
    //         cout << h << " ";
    //     cout << "\n";
    // }
    // vector<int> v = {1, 2, 3};
    // vector<int> l(v.end() - v.begin() - 1);
    // copy(v.begin() + 1, v.end(), l.begin());
    // for (int i : l)
    //     cout << i << " ";
    return 0;
}
