struct TreeNode
{
    int val;
    TreeNode *right;
    TreeNode *left;
};

class Solution
{
  public:
    TreeNode *invertTree(TreeNode *node)
    {
        if (node == nullptr)
        {
            return node;
        }

        TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;

        invertTree(node->left);
        invertTree(node->right);

        return node;
    }
};
