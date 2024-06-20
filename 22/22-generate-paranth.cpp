#include <string>
#include <vector>

using namespace std;

auto backtrack(int op, int cl, string &l, int n, vector<string> &ans)
{
    if (op == n && cl == n)
    {
        ans.push_back(l);
        return;
    }

    if (op < n)
    {
        l += "(";
        backtrack(op + 1, cl, l, n, ans);
        l.pop_back();
    }

    if (op > cl)
    {
        l += ")";
        backtrack(op, cl + 1, l, n, ans);
        l.pop_back();
    }
};

class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        string l;
        vector<string> ans;

        backtrack(0, 0, l, n, ans);

        return ans;
    }
};
