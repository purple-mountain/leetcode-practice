#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, bool> map;
        int max_len = 0;

        for (int i = 0, j = 0; j < s.size();)
        {
            if (map[s[j]])
            {
                map[s[i]] = false;
                i++;
            }
            else
            {
                map[s[j]] = true;
                j++;
                max_len = max(max_len, j - i);
            }
        }

        return max_len;
    }
};
