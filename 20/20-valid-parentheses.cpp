#include <stack>
#include <string>

using namespace std;

class Solution
{
  public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (st.empty())
                {
                    return false;
                }

                switch (s[i])
                {
                case ')':
                    if (st.top() != '(')
                    {
                        return false;
                    }

                    st.pop();
                    break;
                case '}':
                    if (st.top() != '{')
                    {
                        return false;
                    }

                    st.pop();
                    break;
                case ']':
                    if (st.top() != '[')
                    {
                        return false;
                    }

                    st.pop();
                    break;
                default:
                    return false;
                }
            }
            else
            {
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};
