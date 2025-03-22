#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> rnk;
int find(int i)
{
    if (par[i] == i)
        return i;
    return par[i] = find(par[i]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (rnk[a] >= rnk[b])
    {
        rnk[a]++;
        par[b] = a;
    }
    else
    {
        rnk[b]++;
        par[a] = b;
    }
}
int countCompleteComponents(int n, vector<vector<int>> &edges)
{
    par.resize(n, 0);
    rnk.resize(n, 1);
    for (int i = 0; i < n; i++)
        par[i] = i;
    unordered_map<int, pair<int, int>> group;
    set<int> visited;
    for (auto x : edges)
    {
        Union(x[0], x[1]);
    }
    for (auto x : edges)
    {
        if (group.count(find(x[0])))
        {
            pair<int, int> y = group[find(x[0])];
            int grEdges = y.second;
            grEdges++;
            int grVer = y.first;
            if (!visited.count(x[0]))
                grVer++;
            if (!visited.count(x[1]))
                grVer++;
            visited.insert(x[0]);
            visited.insert(x[1]);
            group[find(x[0])] = {grVer, grEdges};
        }
        else
        {
            group[find(x[0])] = {2, 1};
            visited.insert(x[0]);
            visited.insert(x[1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!group.count(find(i)))
        {
            group[find(i)] = {1, 0};
        }
    }

    int connGroup = 0;
    for (auto &k : group)
    {
        cout << k.first << " ";
        int grVer = k.second.first;
        int grEdges = k.second.second;
        if (grEdges == grVer * (grVer - 1) / 2)
            connGroup++;
    }
    return connGroup;
}

int main()
{
}