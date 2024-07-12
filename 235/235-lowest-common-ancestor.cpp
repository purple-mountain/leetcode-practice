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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *f, TreeNode *s)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->val <= max(f->val, s->val) && root->val >= min(f->val, s->val))
        {
            return root;
        }

        if (root->val >= max(f->val, s->val))
        {
            return lowestCommonAncestor(root->left, f, s);
        }

        return lowestCommonAncestor(root->right, f, s);
    }
};
