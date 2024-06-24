#include <vector>

using namespace std;

class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size();

        while (low < high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] >= nums[low])
            {
                if (nums[mid] > target && nums[low] <= target)
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && nums[high - 1] >= target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid;
                }
            }
        }

        return -1;
    };
};
