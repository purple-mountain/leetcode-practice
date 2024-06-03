#include <algorithm>
#include <array>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<array<int, 26>, vector<string>> map;
        vector<vector<string>> ans;

        for (string str : strs)
        {
            array<int, 26> count;

            for (char ch : str)
            {
                count[ch - 'a']++;
            }

            map[count].push_back(str);
        }

        for (auto m : map)
        {
            ans.push_back(m.second);
        }

        return ans;
    }
};

class SolutionWithSorting
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;

        for (auto str : strs)
        {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            map[sortedStr].push_back(str);
        }

        for (auto m : map)
        {
            ans.push_back(m.second);
        }

        return ans;
    }
};
