#include <bits/stdc++.h>
using namespace std;

vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
{
    unordered_map<string, list<string>> graph;
    unordered_map<string, int> indegree;
    queue<string> que;
    set<string> visited;
    set<string> supp;
    for (int i = 0; i < supplies.size(); i++)
    {
        indegree[supplies[i]] = 0;
        que.push(supplies[i]);
        supp.insert(supplies[i]);
    }

    int n = recipes.size();
    for (int i = 0; i < n; i++)
    {
        for (string ing : ingredients[i])
        {
            graph[ing].push_back(recipes[i]);
            indegree[recipes[i]]++;
        }
    }

    while (que.size())
    {
        string node = que.front();
        que.pop();
        visited.insert(node);
        for (string neighbor : graph[node])
        {
            if (visited.count(neighbor))
                continue;
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                que.push(neighbor);
        }
    }
    vector<string> ans;
    for (string s : visited)
    {
        if (!supp.count(s))
            ans.push_back(s);
    }
    return ans;
}

int main()
{
}