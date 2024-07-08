#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
  public:
    bool isBalanced(TreeNode *root)
    {
        return dfs(root) == -1 ? false : true;
    }

    int dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int l = dfs(node->left);
        int r = dfs(node->right);

        if (l == -1 || r == -1 || abs(l - r) > 1)
        {
            return -1;
        }

        return max(l, r) + 1;
    }
};
