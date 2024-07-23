#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        unordered_map<int, bool> m;

        dfs(ans, tmp, nums, m);

        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &tmp, vector<int> &nums, unordered_map<int, bool> &m)
    {
        if (tmp.size() == nums.size())
        {
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (m[nums[i]])
            {
                continue;
            }

            tmp.push_back(nums[i]);
            m[nums[i]] = true;
            dfs(ans, tmp, nums, m);
            tmp.pop_back();
            m[nums[i]] = false;
        }
    }
};
