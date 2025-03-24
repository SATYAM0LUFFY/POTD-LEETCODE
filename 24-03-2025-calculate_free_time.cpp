#include <bits/stdc++.h>
using namespace std;

int countDays(int days, vector<vector<int>> &meetings)
{
    int n = meetings.size();
    vector<int> startTime;
    vector<int> endTime;
    for (auto &meet : meetings)
    {
        startTime.push_back(meet[0]);
        endTime.push_back(meet[1]);
    }
    sort(startTime.begin(), startTime.end());
    sort(endTime.begin(), endTime.end());
    for (int i = 0; i < n; i++)
        cout << startTime[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << endTime[i] << " ";
    int i = 0;
    int j = 0;
    int activeMeetings = 0;
    int freeTime = 0;
    while (i < n)
    {
        if (i == 0)
        {
            freeTime = startTime[0] - 1;
            activeMeetings++;
            i++;
        }
        else if (startTime[i] == endTime[j])
        {
            i++;
            j++;
        }
        else if (startTime[i] < endTime[j])
        {
            activeMeetings++;
            i++;
        }
        else if (startTime[i] > endTime[j])
        {
            activeMeetings--;
            if (activeMeetings == 0)
            {
                cout << "in here";
                freeTime = freeTime + (startTime[i] - endTime[j] - 1);
            }
            j++;
        }
    }
    freeTime = freeTime + (days - endTime[n - 1]);
    return freeTime;
}
int main()
{
}