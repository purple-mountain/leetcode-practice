#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool couldEatAllBananas(vector<int> &piles, int h, int k)
{
    int count = 0;
    auto divide = [](int a, int b) { return (a + b - 1) / b; };

    for (auto &p : piles)
    {
        count += divide(p, k);
    }

    return count <= h;
}

class Solution
{
  public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int ans = 0;
        int low = 1;
        int high = *max_element(piles.begin(), piles.end()) + 1;

        while (low < high)
        {
            int mid = (low + high) / 2;

            if (couldEatAllBananas(piles, h, mid))
            {
                ans = mid;
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};
