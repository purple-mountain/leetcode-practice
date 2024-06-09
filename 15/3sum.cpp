#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i - 1] == nums[i])
            {
                continue;
            }

            for (int j = i + 1, k = nums.size() - 1; j < k;)
            {
                int sum = nums[j] + nums[k] + nums[i];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    while (nums[j] == nums[j - 1] && j < k)
                    {
                        j++;
                    }
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }

        return ans;
    }
};
