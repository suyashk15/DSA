//Topological sort using Kahn's algorithm.
// TS is possible only for directed acyclic graphs.
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].emplace_back(v); // Directed graph
}

vector<int> kahns_ts(vector<int> graph[], int size)
{
    vector<int> result;
    vector<int> indegree(size,0); // no. of rays incident

    for(int i=0; i<size; i++)
        for(int j=0; j<graph[i].size(); j++)
            indegree[graph[i][j]]++;
    
    queue<int> q;

    for(int i=0; i<size; i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        result.emplace_back(v);

        for(auto i=graph[v].begin(); i!=graph[v].end(); i++)
        {
            indegree[*i]--;
            if(indegree[*i]==0)
                q.push(*i);
        }
    }
    return result;
}

int main()
{
    int size = 5;
    vector<int> graph[size];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);

    vector<int> result = kahns_ts(graph, size);
    if (result.size() != size)
       cout << "Topological sort not possible" << endl;
    else
    {
        cout << "Topological sort using Kahn's algorithm: " << endl;
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    cout << graph->size();
    return 0;
}