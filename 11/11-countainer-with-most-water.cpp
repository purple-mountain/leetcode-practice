#include <vector>
using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;

        for (int i = 0, j = height.size() - 1; i < j;)
        {
            int area = (j - i) * min(height[i], height[j]);

            if (area > max_area)
            {
                max_area = area;
            }

            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return max_area;
    }
};
