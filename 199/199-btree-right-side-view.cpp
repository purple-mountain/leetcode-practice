#include <vector>

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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;

        if (root == nullptr)
        {
            return ans;
        }

        dfs(root, ans, 0);

        return ans;
    }

    void dfs(TreeNode *node, vector<int> &ans, int h)
    {
        if (node == nullptr)
        {
            return;
        }

        if (h >= ans.size())
        {
            ans.push_back(node->val);
        }

        dfs(node->right, ans, h + 1);
        dfs(node->left, ans, h + 1);
    }
};
