#include <algorithm>
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
        map<vector<int>, vector<string>> map;
        vector<vector<string>> ans;

        for (string str : strs)
        {
            vector<int> count(26, 0);

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
