#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> tmp;

        dfs(ans, tmp, 0, 0, candidates, target);

        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &tmp, int i, int sum, vector<int> &candidates, int target)
    {
        if (sum == target)
        {
            ans.push_back(tmp);
            return;
        }

        if (i >= candidates.size() || sum > target)
        {
            return;
        }

        tmp.push_back(candidates[i]);
        dfs(ans, tmp, i, sum + candidates[i], candidates, target);
        tmp.pop_back();
        dfs(ans, tmp, i + 1, sum, candidates, target);
    }
};
