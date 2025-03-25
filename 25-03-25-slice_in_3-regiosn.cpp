#include <bits/stdc++.h>
using namespace std;

bool merge(vector<vector<int>> &x)
{
    vector<vector<int>> merged;
    merged.push_back(x[0]);
    int n = x.size();
    for (int i = 1; i < n; i++)
    {
        int start = x[i][0];
        int end = x[i][1];
        vector<int> last = merged[merged.size() - 1];
        if (last[1] <= start)
            merged.push_back({start, end});
        else
        {
            merged[merged.size() - 1][1] = max(end, merged[merged.size() - 1][1]);
        }
    }
    return merged.size() >= 3;
}
bool checkValidCuts(int a, vector<vector<int>> &rectangles)
{
    int n = rectangles.size();
    vector<vector<int>> x;
    vector<vector<int>> y;
    for (int i = 0; i < n; i++)
    {
        x.push_back({rectangles[i][0], rectangles[i][2]});
        y.push_back({rectangles[i][1], rectangles[i][3]});
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    return merge(x) || merge(y);
}

int main()
{
}