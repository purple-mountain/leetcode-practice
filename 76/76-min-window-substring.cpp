#include <iostream>
#include <string>

using namespace std;

bool valid(int f[58], int s[58])
{
    for (int i = 0; i < 58; i++)
    {
        if (s[i] != 0 && !(s[i] <= f[i]))
        {
            return false;
        }
    }

    return true;
}

class Solution
{
  public:
    string minWindow(string s, string t)
    {
        int s_count[58] = {};
        int t_count[58] = {};
        int ans_idx = -1;
        int max_len = s.size();
        string ans;

        for (auto ch : t)
        {
            t_count[ch - 'A']++;
        }

        for (int i = 0, j = 0; j < s.size();)
        {
            s_count[s[j] - 'A']++;

            if (s_count[s[j] - 'A'] != t_count[s[j] - 'A'])
            {
                j++;
            }
            else if (valid(s_count, t_count))
            {
                int dist = j - i + 1;

                if (max_len >= dist)
                {
                    max_len = dist;
                    ans_idx = i;
                }

                s_count[s[i] - 'A']--;
                s_count[s[j] - 'A']--;
                i++;
            }
            else
            {
                j++;
            }
        }

        for (int i = ans_idx; i < max_len + ans_idx && i >= 0; i++)
        {
            ans += s[i];
        }

        return ans;
    }
};
