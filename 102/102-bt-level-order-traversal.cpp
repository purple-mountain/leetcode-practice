#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (root == nullptr)
        {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int len = q.size();
            vector<int> level(len);

            for (int i = 0; i < len; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                level[i] = node->val;

                if (node->left)
                {
                    q.push(node->left);
                }

                if (node->right)
                {
                    q.push(node->right);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};
