#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// class Graph
// {
//     int V;
//     list<int> *adj;

//     public:

//     Graph(int V);
//     void addedge(int v, int w);
//     void BFS(int s);
// };

// Graph(int V)
// {
//     this->V = V;
//     adj = new list<int>[V];
// }

// void addedge(int v, int w)
// {
//     adj[v].push_back(w);
// }

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

void BFS(vector<int> graph[], int start)
{
    vector<bool> visited(graph->size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int v = q.front();
        cout << v << "  ";
        q.pop();
        // Enqueue all adjacent nodes of v and mark them visited
        for (auto i = graph[v].begin(); i != graph[v].end(); i++) {
            
            if (!visited[*i]) {
                q.push(*i);
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

    cout << "BFS traversal starting from node 0:" << "  ";
    BFS(graph, 0);
    return 0;
}

