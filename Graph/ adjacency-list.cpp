#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

class AdjacencyListGraph
{
private:
    int numVertices;                    // Number of vertices
    bool isDirected;                    // Directed or Undirected
    vector<vector<pair<int, int>>> adj; // Adjacency list: pair<neighbor, weight>

public:
    // Constructor
    AdjacencyListGraph(int vertices, bool directed = false)
        : numVertices(vertices), isDirected(directed)
    {
        adj.resize(vertices);
    }

    // Add edge to the graph
    void addEdge(int u, int v, int weight = 1)
    {
        adj[u].emplace_back(v, weight);
        if (!isDirected)
        {
            adj[v].emplace_back(u, weight);
        }
    }

    // Display the adjacency list of the graph
    void displayGraph()
    {
        for (int i = 0; i < numVertices; ++i)
        {
            cout << "Vertex " << i << ": ";
            for (const auto &neighbor : adj[i])
            {
                cout << "(Dest: " << neighbor.first << ", Weight: " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

    // Depth First Search (DFS)
    void dfs(int start)
    {
        vector<bool> visited(numVertices, false);
        stack<int> s;
        s.push(start);
        cout << "DFS Traversal: ";

        while (!s.empty())
        {
            int node = s.top();
            s.pop();

            if (!visited[node])
            {
                cout << node << " ";
                visited[node] = true;
            }

            for (const auto &neighbor : adj[node])
            {
                if (!visited[neighbor.first])
                {
                    s.push(neighbor.first);
                }
            }
        }
        cout << endl;
    }

    // Breadth First Search (BFS)
    void bfs(int start)
    {
        vector<bool> visited(numVertices, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (const auto &neighbor : adj[node])
            {
                if (!visited[neighbor.first])
                {
                    visited[neighbor.first] = true;
                    q.push(neighbor.first);
                }
            }
        }
        cout << endl;
    }
};

class AdjacencyMatrixGraph
{
private:
    int numVertices;               // Number of vertices
    bool isDirected;               // Directed or Undirected
    vector<vector<int>> adjMatrix; // Adjacency matrix

public:
    // Constructor
    AdjacencyMatrixGraph(int vertices, bool directed = false)
        : numVertices(vertices), isDirected(directed)
    {
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    // Add edge to the graph
    void addEdge(int u, int v, int weight = 1)
    {
        adjMatrix[u][v] = weight;
        if (!isDirected)
        {
            adjMatrix[v][u] = weight;
        }
    }

    // Display the adjacency matrix of the graph
    void displayGraph()
    {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; ++i)
        {
            for (int j = 0; j < numVertices; ++j)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // Example: Adjacency List Graph
    AdjacencyListGraph listGraph(5);
    listGraph.addEdge(0, 1, 2);
    listGraph.addEdge(0, 4, 1);
    listGraph.addEdge(1, 2, 3);
    listGraph.addEdge(1, 3, 5);
    listGraph.addEdge(1, 4, 4);
    listGraph.addEdge(2, 3, 1);
    listGraph.addEdge(3, 4, 7);

    cout << "Adjacency List Graph:" << endl;
    listGraph.displayGraph();
    listGraph.dfs(0);
    listGraph.bfs(0);

    // Example: Adjacency Matrix Graph
    AdjacencyMatrixGraph matrixGraph(5);
    matrixGraph.addEdge(0, 1, 2);
    matrixGraph.addEdge(0, 4, 1);
    matrixGraph.addEdge(1, 2, 3);
    matrixGraph.addEdge(1, 3, 5);
    matrixGraph.addEdge(1, 4, 4);
    matrixGraph.addEdge(2, 3, 1);
    matrixGraph.addEdge(3, 4, 7);

    cout << endl
         << "Adjacency Matrix Graph:" << endl;
    matrixGraph.displayGraph();

    return 0;
}