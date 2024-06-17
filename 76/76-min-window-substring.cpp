#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    string minWindow(string s, string t)
    {
        if (t.size() == 0)
        {
            return "";
        }

        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        int ans_idx = -1;
        int max_len = s.size();
        string ans;

        for (auto ch : t)
        {
            t_map[ch]++;
        }

        int have = 0, need = t_map.size();
        for (int i = 0, j = i; j < s.size();)
        {
            if (have == need)
            {
                int dist = j - i + 1;
                if (dist <= max_len)
                {
                    max_len = dist;
                    ans_idx = i;
                }

                s_map[s[i]]--;
                if (t_map[s[i]] && s_map[s[i]] < t_map[s[i]])
                {
                    have--;
                    j++;
                }
                i++;
            }
            else
            {
                s_map[s[j]]++;

                if (t_map[s[j]] && s_map[s[j]] == t_map[s[j]])
                {
                    have++;
                }

                if (need != have)
                {
                    j++;
                }
            }
        }

        for (int i = ans_idx; i < max_len + ans_idx && i >= 0; i++)
        {
            ans += s[i];
        }

        return ans;
    }
};
