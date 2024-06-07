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
        for (int i = 0, j = s.size() - 1; j >= i;)
        {
            if (!is_valid(s[i]))
            {
                i++;
            }
            else if (!is_valid(s[j]))
            {
                j--;
            }
            else
            {
                if (tolower(s[i]) != tolower(s[j]))
                {
                    return false;
                }

                i++;
                j--;
            }
        }

        return true;
    }
};
