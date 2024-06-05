#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, vector<char>> row_map;
        unordered_map<int, vector<char>> column_map;
        map<vector<int>, vector<char>> squares;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }

                if (find(row_map[i].begin(), row_map[i].end(), board[i][j]) != row_map[i].end() ||
                    find(column_map[j].begin(), column_map[j].end(), board[i][j]) != column_map[j].end() ||
                    find(squares[{i / 3, j / 3}].begin(), squares[{i / 3, j / 3}].end(), board[i][j]) !=
                        squares[{i / 3, j / 3}].end())
                {
                    return false;
                }

                row_map[i].push_back(board[i][j]);
                column_map[j].push_back(board[i][j]);
                squares[{i / 3, j / 3}].push_back(board[i][j]);
            }
        }

        return true;
    }
};
