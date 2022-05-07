#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

void DFS(vector<int> graph[], int start)
{
    stack<int> s;
    vector<bool> visited(graph->size(), false);

    s.push(start);
    visited[start]=true;

    while(!s.empty())
    {
        int v = s.top();
        cout << v <<" ";
        s.pop();

        for(auto i=graph[v].begin(); i!=graph[v].end(); i++)
        {
            if(!visited[*i])
            {
                s.push(*i);
                visited[*i] = true;
            }
        }
    }
}

int main()
{
    int V = 7; // vertices
    vector<int> graph[V];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);

    cout << "DFS traversal starting from node 0:" << "  ";
    DFS(graph, 0);
    return 0;
}