#include <vector>

using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0;
        int i = 0;

        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[i] > prices[j])
            {
                i = j;
            }

            max_profit = max(max_profit, prices[j] - prices[i]);
        }

        return max_profit;
    }
};
