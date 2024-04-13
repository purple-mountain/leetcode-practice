#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        vector<vector<int>> bucket(nums.size() + 1);
        vector<int> ans;

        for (auto num : nums)
        {
            map[num]++;
        }

        for (auto m : map)
        {
            bucket[m.second].push_back(m.first);
        }

        for (auto i = bucket.size(); i--;)
        {
            for (auto b : bucket[i])
            {
                if (ans.size() >= k)
                {
                    return ans;
                }

                ans.push_back(b);
            }
        }

        return ans;
    }
};
