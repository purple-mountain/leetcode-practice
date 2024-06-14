#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    int characterReplacement(string s, int k)
    {
        int ans = 0;
        int max_freq = 0;
        unordered_map<char, int> map;

        for (int i = 0, j = i; j < s.size() && j >= i;)
        {
            int dist = j - i + 1;
            map[s[j]]++;

            max_freq = max(map[s[j]], max_freq);

            if (dist - max_freq <= k)
            {
                ans = max(ans, dist);
                j++;
            }
            else
            {
                map[s[j]]--;
                map[s[i]]--;
                i++;
            }
        }

        return ans;
    }
};
