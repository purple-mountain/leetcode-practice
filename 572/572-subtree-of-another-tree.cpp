struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
  public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr || subRoot == nullptr)
        {
            return false;
        }

        if (isSameTree(root, subRoot))
        {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

  private:
    bool isSameTree(TreeNode *s, TreeNode *f)
    {
        if (s == nullptr && f == nullptr)
        {
            return true;
        }

        if (s == nullptr || f == nullptr || s->val != f->val)
        {
            return false;
        }

        return isSameTree(s->left, f->left) && isSameTree(s->right, f->right);
    }
};
