#include <vector>

using namespace std;

class Solution
{
  public:
    int findMin(vector<int> &nums)
    {
        int ans = nums[0];
        int low = 0;
        int high = nums.size();

        while (low < high)
        {
            int mid = (low + high) / 2;
            if (nums[high - 1] >= nums[mid])
            {
                ans = min(nums[mid], ans);
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};
