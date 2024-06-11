#include <vector>

using namespace std;

class Solution
{
  public:
    int trap(vector<int> &height)
    {
        int water = 0;
        int lmax = height[0];
        int rmax = height[height.size() - 1];

        for (int l = 0, r = height.size() - 1; r > l;)
        {
            if (lmax > rmax)
            {
                r--;
                rmax = max(rmax, height[r]);
                water += rmax - height[r];
            }
            else
            {
                l++;
                lmax = max(lmax, height[l]);
                water += lmax - height[l];
            }
        }

        return water;
    }
};
