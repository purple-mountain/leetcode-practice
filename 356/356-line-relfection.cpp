#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;

struct VectorHasher
{
    int operator()(const vector<int> &V) const
    {
        int hash = V.size();
        for (auto &i : V)
        {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

bool isReflected(vector<vector<int>> &points)
{
    unordered_map<vector<int>, bool, VectorHasher> pointsM;
    int min_x = INT_MIN;
    int max_x = INT_MAX;
    int line;

    for (auto point : points)
    {
        min_x = min(min_x, point[0]);
        max_x = max(max_x, point[0]);
        pointsM[point] = true;
    }

    line = (min_x + max_x) / 2;

    for (auto &point : points)
    {
        int reflection = (line - point[0]) + line;

        if (!pointsM[{reflection, point[1]}])
        {
            return false;
        }
    }

    return true;
}
