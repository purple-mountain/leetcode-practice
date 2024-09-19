#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> marked(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (backtrack(board, marked, board.size(), board[i].size(), word, 0, i, j))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>> &board, vector<vector<bool>> &marked, int rowSize, int colSize, string word, int i, int m,
                   int n)
    {
        if (i == word.size())
        {
            return true;
        }

        if (m < 0 || n < 0 || m >= rowSize || n >= colSize || marked[m][n])
        {
            return false;
        }

        if (board[m][n] == word[i])
        {
            marked[m][n] = true;
            if (backtrack(board, marked, rowSize, colSize, word, i + 1, m + 1, n) ||
                backtrack(board, marked, rowSize, colSize, word, i + 1, m, n + 1) ||
                backtrack(board, marked, rowSize, colSize, word, i + 1, m - 1, n) ||
                backtrack(board, marked, rowSize, colSize, word, i + 1, m, n - 1))
            {
                return true;
            };
            marked[m][n] = false;
        }

        marked[m][n] = false;
        return false;
    }
};
