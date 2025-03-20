//https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/?envType=daily-question&envId=2025-03-20
#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> rnk;
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (rnk[a] > rnk[b])
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
int find(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = find(par[x]);
}
vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
{
    par.resize(n);
    for (int i = 0; i < n; i++)
        par[i] = i;
    rnk.resize(n, 1);
    vector<int> and_array(n, INT_MAX);

    int k = edges.size();

    for (int i = 0; i < k; i++)
    {
        int par1 = find(edges[i][0]);
        int par2 = find(edges[i][1]);
        Union(edges[i][0], edges[i][1]);
        and_array[find(edges[i][0])] = and_array[par1] & and_array[par2] & edges[i][2];
    }
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << and_array[i] << " ";

    for (int i = 0; i < n; i++)
        cout << find(i) << " ";
    vector<int> ans;
    for (int i = 0; i < query.size(); i++)
    {
        if (find(query[i][0]) != find(query[i][1]))
            ans.push_back(-1);
        else
        {
            ans.push_back(and_array[find(query[i][0])]);
        }
    }
    return ans;
}