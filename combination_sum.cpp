#include <iostream>
using namespace std;
vector<vector<int>> ansAll;
void combination(vector<int> cand, int tar, vector<int> ans, int j)
{
    if (tar == 0)
    {
        ansAll.push_back(ans);
        return;
    }
    if (tar < 0)
        return;
    for (int i = j; i < cand.size(); i++)
    {
        ans.push_back(cand[i]);
        combination(cand, tar - cand[i], ans, i);
        ans.pop_back();
    }
}
int main()
{
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    combination(candidates, target, {}, 0);
    return ansAll;
}