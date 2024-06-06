#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
  public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> set;
        int count = 0;

        for (auto num : nums)
        {
            set.insert(num);
        }

        for (auto s : set)
        {
            if (!set.contains(s + 1))
            {
                int len = 0;

                while (set.contains(s - len))
                {
                    len++;
                }

                count = max(len, count);
            }
        }

        return count;
    }
};
