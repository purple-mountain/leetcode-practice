#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  private:
    unordered_map<char, string> m{
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };

  public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        string tmp;

        if (digits == "")
        {
            return ans;
        }

        backtrack(ans, tmp, m[digits[0]], digits, 0);

        return ans;
    }

    void backtrack(vector<string> &ans, string tmp, string digitStr, string digits, int idx)
    {
        if (idx == digits.length())
        {
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i < digitStr.length(); i++)
        {
            backtrack(ans, tmp + digitStr[i], m[digits[idx + 1]], digits, idx + 1);
        }
    }
};
