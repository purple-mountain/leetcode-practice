struct TreeNode
{
    int val;
    TreeNode *right;
    TreeNode *left;
};

class Solution
{
  public:
    int ans;
    int count;
    int kthSmallest(TreeNode *root, int k)
    {
        dfs(root, k);
        return this->ans;
    }

    void dfs(TreeNode *node, int k)
    {
        if (node == nullptr)
        {
            return;
        }

        dfs(node->left, k);

        count++;

        if (count == k)
        {
            ans = node->val;
            return;
        }

        dfs(node->right, k);
    }
};
