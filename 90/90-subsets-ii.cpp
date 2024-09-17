#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> tmp;

        sort(nums.begin(), nums.end());

        backtrack(ans, tmp, nums, 0);

        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> &tmp, vector<int> &nums, int idx)
    {
        if (idx >= nums.size())
        {
            ans.push_back(tmp);
            return;
        }

        tmp.push_back(nums[idx]);
        backtrack(ans, tmp, nums, idx + 1);
        tmp.pop_back();

        while (idx < nums.size() - 1 && nums[idx] == nums[idx + 1])
        {
            idx++;
        }

        backtrack(ans, tmp, nums, idx + 1);
    }
};
