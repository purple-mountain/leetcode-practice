#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> tmp;

        dfs(ans, tmp, nums, 0);

        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &tmp, vector<int> &nums, int p)
    {
        ans.push_back(tmp);

        for (int i = p; i < nums.size(); i++)
        {
            tmp.push_back(nums[i]);
            dfs(ans, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
};
