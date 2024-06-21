#include <vector>

using namespace std;

class Solution
{
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int col_len = matrix[0].size();
        int low_row = 0;
        int high_row = matrix.size();

        int row_idx;

        while (low_row < high_row)
        {
            int middle = (low_row + high_row) / 2;

            if (matrix[middle][0] <= target && matrix[middle][col_len - 1] >= target)
            {
                row_idx = middle;
                break;
            }
            else if (matrix[middle][0] > target)
            {
                high_row = middle;
            }
            else
            {
                low_row = middle + 1;
            }
        }

        int low = 0;
        int high = col_len;

        while (low < high)
        {
            int mid = (low + high) / 2;

            if (matrix[row_idx][mid] == target)
            {
                return true;
            }
            else if (matrix[row_idx][mid] > target)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return false;
    }
};
