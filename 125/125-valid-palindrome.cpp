#include <cctype>
#include <string>

using namespace std;

bool is_valid(char s)
{
    return isdigit(s) || isalpha(s);
}

class Solution
{
  public:
    bool isPalindrome(string s)
    {
        string tmp;

        for (auto ch : s)
        {
            if (is_valid(ch))
            {
                tmp += tolower(ch);
            }
        }

        for (int i = 0; i < (tmp.size() + 1) / 2; i++)
        {
            if (tmp[i] != tmp[tmp.size() - 1 - i])
            {
                return false;
            }
        }

        return true;
    }
};
