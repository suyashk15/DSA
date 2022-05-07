#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<pair<int,int>>> &graph, int u, int v, int w)
{
    graph[u].push_back(make_pair(v,w));
    graph[v].push_back(make_pair(u,w));
}

vector<int> dijkstra(vector<vector<pair<int,int>>> graph, int start)
{
    // Initialising all distances to infinity, and 0 from start vertex
    vector<int> dist(graph.size(), INT_MAX);
    dist[start]=0;

    // min heap syntax. Its a pair of <weight,vertex>
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;
    minh.push(make_pair(0,start));

    while(!minh.empty())
    {
        int min_v = minh.top().second; //vertex with min distance
        minh.pop();

        for(int i=0; i<graph[min_v].size(); i++)
        {
            int vertex = graph[min_v][i].first;
            int weight = graph[min_v][i].second;

            if(dist[vertex] > dist[min_v]+weight)
            {
                dist[vertex] = dist[min_v]+weight;
                minh.push(make_pair(dist[vertex], vertex));
            }
        }
    }
    return dist;
}

int main()
{
    vector<vector<pair<int,int>>> graph(9, vector<pair<int,int>>(9));

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    vector<int> dist = dijkstra(graph, 0);
    // Print shortest distances stored in dist[]
    cout << "Vertex      Distance from Source" << endl;
    for (int i = 0; i < 9; ++i)
        cout << i << "\t\t" << dist[i] << endl;
    //return 0;

}