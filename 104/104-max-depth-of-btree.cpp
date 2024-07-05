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
    int maxDepth(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        return max(maxDepth(node->left), maxDepth(node->right)) + 1;
    }
};
