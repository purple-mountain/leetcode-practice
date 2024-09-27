#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> tmp;

        backtrack(ans, tmp, s, 0);

        return ans;
    }

    bool isPalindrome(string f, int start, int end)
    {
        for (int l = start, r = end; l < r; l++, r--)
        {
            if (f[l] != f[r])
            {
                return false;
            }
        }

        return true;
    }

    void backtrack(vector<vector<string>> &ans, vector<string> &tmp, string s, int idx)
    {
        if (idx == s.length())
        {
            ans.push_back(tmp);
            return;
        }

        for (int i = idx; i < s.length(); i++)
        {
            if (isPalindrome(s, idx, i))
            {
                tmp.push_back(s.substr(idx, i - idx + 1));
                backtrack(ans, tmp, s, i + 1);
                tmp.pop_back();
            }
        }
    }
};
