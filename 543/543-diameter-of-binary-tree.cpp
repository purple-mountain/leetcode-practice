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
  private:
    int mx = 0;
    int findHeight(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int l = findHeight(node->left);
        int r = findHeight(node->right);
        mx = std::max(mx, l + r);

        return max(l, r) + 1;
    }

  public:
    int diameterOfBinaryTree(TreeNode *node)
    {
        findHeight(node);

        return mx;
    }
};
