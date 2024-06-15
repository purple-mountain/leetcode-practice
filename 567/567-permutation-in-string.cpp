#include <string>

using namespace std;

class Solution
{
  public:
    bool checkInclusion(string s1, string s2)
    {
        int f[26] = {};
        int s[26] = {};

        for (auto s : s1)
            f[s - 'a']++;

        for (int i = 0, j = i; j < s2.size();)
        {
            s[s2[j] - 'a']++;
            int len = j - i + 1;

            if (len == s1.size())
            {
                bool valid = true;
                for (int k = 0; k < 26; k++)
                {
                    if (f[k] != s[k])
                    {
                        valid = false;
                    }
                }

                if (valid)
                    return valid;
            }

            if (len < s1.size())
            {
                j++;
            }
            else
            {
                s[s2[i] - 'a']--;
                i++;
                j++;
            }
        }

        return false;
    }
};
