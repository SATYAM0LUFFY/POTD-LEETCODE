// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/?envType=daily-question&envId=2025-03-23

#include <bits/stdc++.h>

using namespace std;

#define pp pair<long long int, long long int>
#define mod 1000000007
#define ll long long int
class Solution
{
public:
    vector<list<pp>> graph;
    int n = 0;
    int count = 0;
    void addEdge(vector<int> edge)
    {
        ll src = edge[0];
        ll dest = edge[1];
        ll wt = edge[2];

        graph[src].push_back({dest, wt});
        graph[dest].push_back({src, wt});
    }
    ll dijkstra()
    {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        set<ll> visited;
        vector<ll> minDis(n, LLONG_MAX);
        vector<ll> ways(n, 0);
        ways[0] = 1;
        minDis[0] = 0;
        pq.push({0, 0});

        while (pq.size())
        {
            pair<ll, ll> top = pq.top();
            pq.pop();
            ll discoveryWt = top.first;
            ll node = top.second;
            visited.insert(node);
            for (pp neighbor : graph[node])
            {
                ll neighborNode = neighbor.first;
                ll edgeWt = neighbor.second;
                if (visited.count(neighborNode))
                    continue;
                if (discoveryWt + edgeWt < minDis[neighborNode])
                {
                    minDis[neighborNode] = discoveryWt + edgeWt;
                    pq.push({discoveryWt + edgeWt, neighborNode});
                    ways[neighborNode] = ways[node];
                }
                else if (discoveryWt + edgeWt == minDis[neighborNode])
                {
                    ways[neighborNode] = (ways[neighborNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
    int countPaths(int a, vector<vector<int>> &roads)
    {
        n = a;
        graph.resize(n, list<pair<ll, ll>>{});
        for (vector<int> &edge : roads)
        {
            addEdge(edge);
        }
        return dijkstra();
    }
};

int main()
{
}