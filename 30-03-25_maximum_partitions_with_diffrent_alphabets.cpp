#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for (int i = 1; i < n; i++)
        {
            if (merged[merged.size() - 1][1] < intervals[i][0])
                merged.push_back(intervals[i]);
            else
                merged[merged.size() - 1][1] = max(merged[merged.size() - 1][1], intervals[i][1]);
        }
        return merged;
    }
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, vector<int>> mp;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (!mp.count(s[i]))
                mp[s[i]] = {i, -1};
            else
                mp[s[i]][1] = i;
        }
        vector<vector<int>> intervals;
        for (auto &[key, value] : mp)
        {
            if (value[1] == -1)
                continue;
            intervals.push_back(value);
        }
        if (intervals.size())
            intervals = merge(intervals);
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < n && j < intervals.size())
        {
            if (intervals[j][0] > i)
            {
                ans.push_back(1);
                i++;
            }
            else
            {
                ans.push_back(intervals[j][1] - intervals[j][0] + 1);
                i = intervals[j][1] + 1;
                j++;
            }
        }

        for (i; i < n; i++)
            ans.push_back(1);
        return ans;
    }
};

int main()
{
}