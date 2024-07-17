#include <climits>
using namespace std;

struct TreeNode
{
    TreeNode *right;
    TreeNode *left;
    int val;
};

class Solution
{
  public:
    bool isValidBST(TreeNode *root)
    {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode *node, long low, long high)
    {
        if (node == nullptr)
        {
            return true;
        }

        if (!(low < node->val && node->val < high))
        {
            return false;
        }

        return dfs(node->left, low, node->val) && dfs(node->right, node->val, high);
    }
};
