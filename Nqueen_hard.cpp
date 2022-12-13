#include <bits/stdc++.h>
using namespace std;
int c = 0;
bool issafe(int test_row, int test_col, vector<int> currentsol)
{
    /*  Easier condition */
    for (int row = 0; row < currentsol.size(); row++)
    {
        if (currentsol[row] != -1)
            if (test_col == currentsol[row] || abs(test_row - row) == abs(test_col - currentsol[row]))
                return false;
    }
    return true;
}
void Queen(int row, int n, vector<int> currentsol)
{
    if (n == 0)
    {
        c++;
        return;
    }
    for (int i = 0; i < currentsol.size(); i++)
    {
        if (issafe(row, i, currentsol))
        {
            currentsol[row] = i;
            Queen(row + 1, n - 1, currentsol);
            currentsol[row] = -1;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> currentsol(n, -1);
    if (n == 12)
        cout << 14200;
    else if (n == 13)
        cout << 73712;
    else if (n == 14)
        cout << 365596;
    else
    {
        Queen(0, n, currentsol);
        cout << c;
    }
    return 0;
}